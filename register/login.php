<!--67200072 宇佐見聡涼 endb2109-->
<!DOCTYPE html>
<html lang="ja">

<head>
  <meta charset="UTF-8">
  <link rel="stylesheet" type="text/css" href="../css/register.css">
  <link rel="stylesheet" type="text/css" href="http://133.54.224.240/penshu4_2021/67200171/last/css/last.css">
  <title>詰将棋</title>
</head>
<h1>ログイン</h1>
<body>
<?php
include_once "../DatabaseAction.inc";
include_once "../DefineData.inc";

$user_name = isset($_POST['USER_NAME']) ? $_POST['USER_NAME'] : "";
$user_pass = isset($_POST['USER_PASS']) ? $_POST['USER_PASS'] : "";
$count = isset($_POST['count']) ? $_POST['count'] + 1 : 0;

if($user_name != "" && $user_pass != "") {
  $con = pg_connect("host=$db_host dbname=$db_name user=$db_user password=$db_pass");
  if($con == FALSE) {
    print "<p>DataBase Connection Error</p>\n";
    exit;
  }

  $sql = "select uname from udata where uname = '$user_name';";
  @$result = da_query($sql);
  $row = pg_num_rows($result);

  $sql = "select pass from udata where uname = '$user_name';";
  @$result = da_query($sql);
  $row2 = pg_num_rows($result);
  if($row2 > 0) {
    $pass = pg_fetch_result($result, 0, 0);


    if($row == 1 && $pass == $user_pass) {
      print <<< EOL1
    <p>おかえりなさい<br>{$user_name}<br>楽しんで</p>
    <form action="../game/select.php" method="post">
      <p><input type="hidden" name="u_name" value="{$user_name}"></p>
      <p><input type="submit" value="ゲームへ"></p>
    </form>
    <a href="../index.html">タイトル画面へ</a>
EOL1;
      exit;
    }
  }

  pg_free_result($result);
  pg_close($con);

  print "<p>ユーザー名またはパスワードが違います.<br></p>\n";
  if($count > 2) {
    print "<p>始めて遊ぶ場合のユーザー登録は<a href=\"./register.php\">こちら</a>\n</p>";
  }
}

  print <<< EOL2
  <p>ユーザー名とパスワードを入力してください</p>
  <form action="login.php" method="POST" name="register_form">
    <p><input type="text" name="USER_NAME"></p>
    <p><input type="password" name="USER_PASS"></p>
    <input type="hidden" name="count" value="{$count}">
    <p><input type="submit" value="ログイン"></p>
  </form>
  <a href="../index.html">タイトル画面へ</a>
EOL2;

?>
</body>

</html>
