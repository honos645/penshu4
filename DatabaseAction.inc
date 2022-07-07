<!--67200072 宇佐見聡涼-->
<?php
  function da_query($sql)
  {
    @$result = pg_query($sql);
    if($result == FALSE) {
      print "<p>DataBase Acquisition Error</p>\n";
      exit;
    }

    return $result;
  }

  function da_piece_in($Board, $Table, $u_name, $id)
  {
    for($y = 0; $y < MAX_Y; $y++) {
      for($x = 0; $x < MAX_X; $x++) {
        if($Board[$x][$y]->getOrd() !== NONE) {
          $db_x = $x + 1;
          $db_y = $y + 1;

          da_query("insert into {$u_name}_buffer values($db_x, $db_y, {$Board[$x][$y]->getNameNum()}, {$Board[$x][$y]->getOrd()}, $id);");
        }
      }
    }

    $n = count($Table);
    for($i = 0; $i < $n; $i++) {
      $sql = "insert into {$u_name}_buffer values(-1, -1, {$Table[$i]->getNameNum()}, {$Table[$i]->getOrd()}, $id);";
      da_query($sql);
    }
  }
?>
