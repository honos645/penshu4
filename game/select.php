<!--67200090 大野和輝 endb2109-->
<!DOCTYPE html>
<html lang="ja">
  <head>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="../css/select.css">
    <link rel="stylesheet" type="text/css" href="http://133.54.224.240/penshu4_2021/67200171/last/css/last.css">
    <title>詰将棋</title>
  </head>

  <body>
    <?php
    include_once "../DefineData.inc";
    include_once "../DatabaseAction.inc";

    /*67200072 宇佐見聡涼*/
    $u_name = isset($_POST['u_name']) ? $_POST['u_name'] : "";
    if($u_name == "") {
      print "<p>ログインしてください</p>\n";
      print "<p>ログイン画面は<a href=\"../register/login.php\">こちら</a></p>\n";
      exit;
    }

    $con = pg_connect("host=$db_host dbname=$db_name user=$db_user password=$db_pass");
    if($con == FALSE) {
      print "<p>DataBase Connection Error</p>\n";
      exit;
    }

    @$result = da_query("select id from question order by id DESC;");
    $max = pg_fetch_result($result, 0, 0);

    print "<h1>問題を選択してね</h1>\n";
    print "<form action=\"./main1.php\" method=\"POST\">\n";
    for($i = 1; $i <= $max; $i++) {
      if($i == 1) {
        print "<p><input type=\"radio\" id=\"$i\" name=\"number\" value=\"$i\" checked><label for=\"$i\">{$i}問目";
      }else {
        print "<p><input type=\"radio\" id=\"$i\" name=\"number\" value=\"$i\"><label for=\"$i\">{$i}問目";
      }
      @$result = da_query("select * from $u_name where id = $i");
      $flg = pg_num_rows($result);
      if($flg > 0) print ":クリア!";
      print "</label></p>\n";
    }
    print "<div id=\"submit\"><p><input type=\"hidden\" name=\"u_name\" value=\"$u_name\">\n<input type=\"submit\" value=\"決定\">\n</p></form>";
    print "<p><a href=\"../index.html\">タイトル画面へ</a></p></div>\n";

    /*67200072 宇佐見聡涼*/
    ?>

  </body>
</html>
