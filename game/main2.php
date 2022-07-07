<!--67200072 宇佐見聡涼 endb2109-->
<!DOCTYPE html>
<html>
  <head lang="ja">
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="../css/game_main.css">
    <link rel="stylesheet" type="text/css" href="../css/main.css">
    <title>詰将棋</title>
  </head>

  <body>
    <h1 class="shogi">詰将棋</h1>
    <?php
    include_once "./function/BoardPrint.inc";
    include_once "./function/MovePiece.inc";
    include_once "./function/PieceData.inc";
    include_once "../DatabaseAction.inc";
    include_once "../DefineData.inc";

    $data_x = isset($_GET['x']) ? $_GET['x'] : "";
    $data_y = isset($_GET['y']) ? $_GET['y'] : "";
    $u_num = isset($_GET['id']) ? $_GET['id'] : "";
    $table_num = isset($_GET['table']) ? $_GET['table'] : "";

    if($data_x == "" && $data_y == "" && $u_num == "") {
      print "<p>予期せぬエラーが発生しました</p>";
      print "<a href=\"../index.html\">メインメニューへ</a>";
      exit;
    }

    /*DB接続*/
    $con = pg_connect("host=$db_host dbname=$db_name user=$db_user password=$db_pass");
    if($con == FALSE) {
      print "<p>DataBase Connection Error</p>\n";
      exit;
    }

    @$result = da_query("select uname from udata where unum = {$u_num}");
    $u_name = pg_fetch_result($result, 0, 0);

    @$result = da_query("select x, y, name, ord from {$u_name}_buffer;");
    $row = pg_num_rows($result);
    $db_data = pg_fetch_all($result);
    @$result = da_query("select id from {$u_name}_buffer;");
    $q_id = pg_fetch_result($result, 0, 0);

    //盤面を保持する配列を生成
    $Table = array();
    for($y = 0; $y < MAX_Y; $y++) {
      for($x = 0; $x < MAX_X; $x++) {
        $Board[$x][$y] = new PieceData(0, 0);
      }
    }
    /*駒情報を配列に格納*/
    $c = 0;
    for($i = 0; $i < $row; $i++) {
      if($db_data[$i]['x'] > 0 && $db_data[$i]['y']) {
        $Board[$db_data[$i]['x'] - 1][$db_data[$i]['y'] - 1]->setAll($db_data[$i]['name'], $db_data[$i]['ord']);
      }else {
        $Table[$c] = new PieceData($db_data[$i]['name'], $db_data[$i]['ord']);
        $c++;
      }
    }

    if($data_x > -1 && $data_y > -1) {
      bp_select($Board, $data_x, $data_y, "main3.php", $u_num);
      bp_table_print($Table);
      print "<h2 class=\"q_id\">第{$q_id}問</h2>\n";
    }else {
      bp_table_select($Board, $Table, $table_num, "main3.php", 1, $u_num);
      print "<h2 class=\"q_id\">第{$q_id}問</h2>\n";
    }
    ?>
    <div class="title">
      <p><input type="button" onclick="location.href='../index.html'" value="タイトル画面へ"></p>
    </div>
  </body>
</html>
