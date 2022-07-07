<!--67200072 宇佐見聡涼 endb2109-->

<!DOCTYPE html>
<html lang="ja">

<head>
  <meta charset="UTF-8">
  <link rel="stylesheet" type="text/css" href="../css/register.css">
  <link rel="stylesheet" type="text/css" href="http://133.54.224.240/penshu4_2021/67200171/last/css/last.css">
  <title>アホ将棋</title>
</head>
<h1>新規登録</h1>
<body>
<?php
include_once "../DatabaseAction.inc";
include_once "../DefineData.inc";

$user_name = isset($_POST['USER_NAME']) ? $_POST['USER_NAME'] : "";
$user_pass = isset($_POST['USER_PASS']) ? $_POST['USER_PASS'] : "";

if($user_name != "" && $user_pass != "") {
  $con = pg_connect("host=$db_host dbname=$db_name user=$db_user password=$db_pass");
  if($con == FALSE) {
    print "<p>DataBase Connection Error</p>\n";
    exit;
  }

  $sql = "select uname from udata where uname = '$user_name';";

  @$result = da_query($sql);
  $row = pg_num_rows($result);

  pg_free_result($result);

  if($row < 1) {
    $sql  = "select * from udata;";
    @$result = da_query($sql);
    $row = pg_num_rows($result);
    $db_id = $row + 1;

    do {
      $unum = random_int(-1.0e5, 1.0e5);
      $sql = "select unum from udata where unum=$unum;";
      @$result = da_query($sql);
      $temp = pg_num_rows($result);
    } while($temp > 0);

    $sql = "insert into udata values($db_id, '$user_name', $unum, '$user_pass', false);";
    @$result = da_query($sql);
    $sql = "create table ".$user_name."_buffer(x int, y int, name int, ord int, id int);";
    @$result = da_query($sql);
    $sql = "create table $user_name(id int);";
    @$result = da_query($sql);


      pg_close($con);

    print <<< EOL1
    <p>ようこそ<br>{$user_name}<br>楽しんで</p>
      <form action="../game/select.php" method="post">
      <input type="hidden" name="u_name" value="{$user_name}">
      <input type="submit" value="難易度選択画面へ">
      </form>
    <a href="../index.html">タイトル画面へ</a>
EOL1;
    exit;
  }

  print "<p>そのユーザー名は既に登録されています.</p>\n";
}

  print <<< EOL2
  <p>ユーザー名とパスワードを入力してください</p>
  <form action="register.php" method="post" name="register_form">
    <p><input type="text" name="USER_NAME"></p>
    <p><input type="text" name="USER_PASS"></p>
    <p><input type="submit" value="登録"></p>
  </form>
  <a href="../index.html">タイトル画面へ</a>
EOL2;

?>
</body>

</html>
