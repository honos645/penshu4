<!--67200072 宇佐見聡涼 endb2109-->
<!DOCTYPE html>
<html>
  <head lang="ja">
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="../css/game_main.css">
    <link rel="stylesheet" type="text/css" href="../css/judge.css">
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
    include_once "./judge.php";

    $data_x = isset($_GET['x']) ? $_GET['x'] : "";
    $data_y = isset($_GET['y']) ? $_GET['y'] : "";
    $data_bx = isset($_GET['bx']) ? $_GET['bx'] : "";
    $data_by = isset($_GET['by']) ? $_GET['by'] : "";
    $u_num = isset($_GET['uid']) ? $_GET['uid'] : "";
    $table_num = isset($_GET['table']) ? $_GET['table'] : "";

    if($u_num == "") {
      $u_num = isset($_POST['uid']) ? $_POST['uid'] : "";
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



    if(!($data_x == "" && $data_y == "" && $data_bx == "" && $data_by == "")) {
      if($data_bx == $data_x && $data_by == $data_y) {
        bp_unselect($Board, "main2.php", $u_num);
        bp_table_unselect($Table, "main2.php", $u_num);
        print "<h2 class=\"q_id\">第{$q_id}問</h2>\n";
      }else {
        if($data_bx == -1 && $data_by == -1) {
          $Board[$data_x][$data_y]->setAll($Table[$table_num]->getNameNum(), MYSELF);
          array_splice($Table, $table_num, 1);
        }else {
          mp_swap($Board[$data_bx][$data_by], $Board[$data_x][$data_y]);
          $flg_prom = mp_checkProm($data_x, $data_y, $data_bx, $data_by, $Board[$data_x][$data_y]->getNameNum(), "main3.php", $u_num);
          if($flg_prom == 1) {
            bp_print($Board);
            bp_table_print($Table);
            print "<h2 class=\"q_id\">第{$q_id}問</h2>\n";
            da_query("delete from {$u_name}_buffer;");
            da_piece_in($Board, $Table, $u_name, $q_id);
            exit;
          }
        }
        bp_print($Board);
        bp_table_print($Table);
        print "<h2 class=\"q_id\">第{$q_id}問</h2>\n";
        judge($data_bx, $data_by, $data_x, $data_y, $u_name, $q_id);
      }
    }else {
      $data_x = isset($_POST['x']) ? $_POST['x'] : "";
      $data_y = isset($_POST['y']) ? $_POST['y'] : "";
      $data_bx = isset($_POST['bx']) ? $_POST['bx'] : "";
      $data_by = isset($_POST['by']) ? $_POST['by'] : "";
      $prom = isset($_POST['prom']) ? $_POST['prom'] : "";

      if($prom == 1) {
        mp_swap($Board[$data_bx][$data_by], $Board[$data_x][$data_y]);
        $Board[$data_x][$data_y]->setProm();
      }else {
        mp_swap($Board[$data_bx][$data_by], $Board[$data_x][$data_y]);
      }
      bp_print($Board);
      bp_table_print($Table);
      print "<h2 class=\"q_id\">第{$q_id}問</h2>\n";
      judge($data_bx, $data_by, $data_x, $data_y, $u_name, $q_id);
    }

    ?>
    <div class="title">
      <p><input type="button" onclick="location.href='../index.html'" value="タイトル画面へ"></p>
    </div>
  </body>
</html>
