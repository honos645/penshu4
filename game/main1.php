<!--67200072 宇佐見聡涼 endb2109-->
<!DOCTYPE html>
<html lang="ja">
  <head>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="../css/game_main.css">
    <link rel="stylesheet" type="text/css" href="../css/main.css">
    <title>詰将棋</title>
  </head>

  <body>
    <h1 class="shogi">詰将棋</h1>
    <?php
    include_once "../DatabaseAction.inc";
    include_once "../DefineData.inc";
    include_once "./function/BoardPrint.inc";
    include_once "./function/MovePiece.inc";
    include_once "./function/PieceData.inc";


    /*DB接続*/
    $con = pg_connect("host=$db_host dbname=$db_name user=$db_user password=$db_pass");
    if($con == FALSE) {
      print "<p>DataBase Connection Error</p>\n";
      exit;
    }

    $u_name = isset($_POST['u_name']) ? $_POST['u_name'] : "";
    if($u_name == "") {
      print "<p>エラーが発生しました.ログインしなおしてください</p>\nログイン画面は<a href=\"../register/login.php\">こちら</a>\n";
      exit;
    }

    $q_id = isset($_POST['number']) ? $_POST['number'] : "";
    @$result = da_query("select id from {$u_name}_buffer;");
    $row = pg_num_rows($result);
    if($row == 0) {
      @$result = da_query("select x, y, name, ord from question where id = $q_id;");
      $row = pg_num_rows($result);
      $db_data = pg_fetch_all($result);
    }elseif($q_id == pg_fetch_result($result, 0, 0)) {
      @$result = da_query("select x, y, name, ord from {$u_name}_buffer;");
      $row = pg_num_rows($result);
      $db_data = pg_fetch_all($result);
    }else {
      @$result = da_query("select x, y, name, ord from question where id = $q_id;");
      $row = pg_num_rows($result);
      $db_data = pg_fetch_all($result);
    }

    $Table = array();
    for($y = 0; $y < MAX_Y; $y++) {
      for($x = 0; $x < MAX_X; $x++) {
        $Board[$x][$y] = new PieceData(0, 0);
      }
    }

    $c = 0;
    for($i = 0; $i < $row; $i++) {
      if($db_data[$i]['x'] > 0 && $db_data[$i]['y'] > 0) {
        $Board[$db_data[$i]['x'] - 1][$db_data[$i]['y'] - 1]->setAll($db_data[$i]['name'], $db_data[$i]['ord']);
      }else {
        $Table[$c] = new PieceData($db_data[$i]['name'], $db_data[$i]['ord']);
        $c++;
      }
    }

    @$result = da_query("select unum from udata where uname = '{$u_name}';");
    $u_num = pg_fetch_result($result, 0, 0);


    bp_unselect($Board, "main2.php", $u_num);
    bp_table_unselect($Table, "main2.php", $u_num);
    print "<h2 class=\"q_id\">第{$q_id}問</h2>\n";

    da_query("delete from {$u_name}_buffer;");
    da_piece_in($Board, $Table, $u_name, $q_id);
    ?>
  <div class="title">
    <p><button onclick="location.href='../index.html'">タイトル画面へ</button></p>
  </div>
  </body>
</html>
