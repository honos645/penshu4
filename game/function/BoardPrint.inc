<!--67200072 宇佐見聡涼-->
<?php
  function bp_change($i)
  {
    /*
    1-9の数字を漢数字に変更する
    bp_change(変換したい数字)
    */
    switch($i) {
        case 1:
          print "一";
          break;
        case 2:
          print "二";
          break;
        case 3:
          print "三";
          break;
        case 4:
          print "四";
          break;
        case 5:
          print "五";
          break;
        case 6:
          print "六";
          break;
        case 7:
          print "七";
          break;
        case 8:
          print "八";
          break;
        case 9;
          print "九";
          break;
      }
  }

  function bp_unselect(&$Board, $file, $id)
  {
    /*
    駒が選択されていないときの画面表示
    bp_unselect(表示させる盤面の配列, 遷移先ファイル名)
    */
    //画面構成
    print "<div class=\"grid\">\n";
    for($i = 1; $i <= MAX_X; $i++) {
      print "<div id=\"x$i\"><p>";
      bp_change($i);
      print "</p></div>\n";
      print "<div id=\"y$i\"><p>$i</p></div>\n";
    }


    for($y = 0; $y < MAX_Y; $y++) {
      for($x = MAX_X - 1; $x >= 0; $x--) {
        switch($Board[$x][$y]->getNameNum()) {
          case 1:
          case -1:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_king.png\" usemap=\"#ne_king_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_king.png\" usemap=\"#n_king_$x$y\"></div>\n";
              print "<map name=\"n_king_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"KING\"></map>\n";
            }
            break;
          case 2:
          case -2:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_king2.png\" usemap=\"#ne_king2_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_king2.png\" usemap=\"#n_king2_$x$y\"></div>\n";
              print "<map name=\"n_king2_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"GYOKU\"></map>\n";
            }
            break;
          case 3:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_rook.png\" usemap=\"#ne_rook_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$x$y\"></div>\n";
              print "<map name=\"n_rook_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"ROOK\"></map>\n";
            }
            break;
          case 4:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_bishop.png\" usemap=\"#ne_bishop_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$x$y\"></div>\n";
              print "<map name=\"n_bishop_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"BISHOP\"></map>\n";
            }
            break;
          case 5:
          case -5:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_gold.png\" usemap=\"#ne_gold_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$x$y\"></div>\n";
              print "<map name=\"n_gold_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"GOLD\"></map>\n";
            }
            break;
          case 6:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_silver.png\" usemap=\"#ne_silver_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$x$y\"></div>\n";
              print "<map name=\"n_silver_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"SILVER\"></map>\n";
            }
            break;
          case 7:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_knight.png\" usemap=\"#ne_knight_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$x$y\"></div>\n";
              print "<map name=\"n_knight_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"KNIGHT\"></map>\n";
            }
            break;
          case 8:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_lance.png\" usemap=\"#ne_lance_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$x$y\"></div>\n";
              print "<map name=\"n_lance_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"LANCE\"></map>\n";
            }
            break;
          case 9:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_pawn.png\" usemap=\"#ne_pawn_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$x$y\"></div>\n";
              print "<map name=\"n_pawn_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"PAWN\"></map>\n";
            }
            break;
          case -3:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_rook.png\" usemap=\"#pe_rook_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_rook.png\" usemap=\"#p_rook_$x$y\"></div>\n";
              print "<map name=\"p_rook_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"P_ROOK\"></map>\n";
            }
            break;
          case -4:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_bishop.png\" usemap=\"#pe_bishop_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_bishop.png\" usemap=\"#p_bishop_$x$y\"></div>\n";
              print "<map name=\"p_bishop_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"P_BISHOP\"></map>\n";
            }
            break;
          case -6:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_silver.png\" usemap=\"#pe_silver_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_silver.png\" usemap=\"#p_silver_$x$y\"></div>\n";
              print "<map name=\"p_silver_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"P_SILVER\"></map>\n";
            }
            break;
          case -7:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_knight.png\" usemap=\"#pe_knight_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_knight.png\" usemap=\"#p_knight_$x$y\"></div>\n";
              print "<map name=\"p_knight_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"P_KNIGHT\"></map>\n";
            }
            break;
          case -8:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_lance.png\" usemap=\"#pe_lance_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_lance.png\" usemap=\"#p_lance_$x$y\"></div>\n";
              print "<map name=\"p_lance_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"P_LANCE\"></map>\n";
            }
            break;
          case -9:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_pawn.png\" usemap=\"#pe_pawn_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_pawn.png\" usemap=\"#p_pawn_$x$y\"></div>\n";
              print "<map name=\"p_pawn_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&id=$id\" alt=\"P_PAWN\"></map>\n";
            }
            break;
          default:
            print "<div id=\"board$x$y\"><img src=\"../ping/null.png\" usemap=\"#null_$x$y\"></div>\n";
        }
      }
    }
  }

  function bp_print(&$Board)
  {
    /*
    画面表示.駒の選択はできない
    bp_unselect(表示させる盤面の配列)
    */

    //画面構成
    print "<div class=\"grid\">\n";
    for($i = 1; $i <= MAX_X; $i++) {
      print "<div id=\"x$i\"><p>";
      bp_change($i);
      print "</p></div>\n";
      print "<div id=\"y$i\"><p>$i</p></div>\n";
    }

    for($y = 0; $y < MAX_Y; $y++) {
      for($x = MAX_X - 1; $x >= 0; $x--) {
        switch($Board[$x][$y]->getNameNum()) {
          case 1:
          case -1:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_king.png\" usemap=\"#ne_king_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_king.png\" usemap=\"#n_king_$x$y\"></div>\n";
            }
            break;
          case 2:
          case -2:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_king2.png\" usemap=\"#ne_king2_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_king2.png\" usemap=\"#n_king2_$x$y\"></div>\n";
            }
            break;
          case 3:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_rook.png\" usemap=\"#ne_rook_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$x$y\"></div>\n";
            }
            break;
          case 4:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_bishop.png\" usemap=\"#ne_bishop_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$x$y\"></div>\n";
            }
            break;
          case 5:
          case -5:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_gold.png\" usemap=\"#ne_gold_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$x$y\"></div>\n";
            }
            break;
          case 6:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_silver.png\" usemap=\"#ne_silver_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$x$y\"></div>\n";
            }
            break;
          case 7:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_knight.png\" usemap=\"#ne_knight_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$x$y\"></div>\n";
            }
            break;
          case 8:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_lance.png\" usemap=\"#ne_lance_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$x$y\"></div>\n";
            }
            break;
          case 9:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_pawn.png\" usemap=\"#ne_pawn_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$x$y\"></div>\n";
            }
            break;
          case -3:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_rook.png\" usemap=\"#pe_rook_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_rook.png\" usemap=\"#p_rook_$x$y\"></div>\n";
            }
            break;
          case -4:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_bishop.png\" usemap=\"#pe_bishop_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_bishop.png\" usemap=\"#p_bishop_$x$y\"></div>\n";
            }
            break;
          case -6:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_silver.png\" usemap=\"#pe_silver_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_silver.png\" usemap=\"#p_silver_$x$y\"></div>\n";
            }
            break;
          case -7:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_knight.png\" usemap=\"#pe_knight_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_knight.png\" usemap=\"#p_knight_$x$y\"></div>\n";
            }
            break;
          case -8:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_lance.png\" usemap=\"#pe_lance_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_lance.png\" usemap=\"#p_lance_$x$y\"></div>\n";
            }
            break;
          case -9:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_pawn.png\" usemap=\"#pe_pawn_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_pawn.png\" usemap=\"#p_pawn_$x$y\"></div>\n";
            }
            break;
          default:
            print "<div id=\"board$x$y\"><img src=\"../ping/null.png\" usemap=\"#null_$x$y\"></div>\n";
        }
      }
    }
  }


  function bp_select(&$Board, $data_x, $data_y, $file, $uid)
  {
    /*
    駒が選択されているときの画面表示
    bp_select(表示させる盤面の配列, 選択された駒のx座標, 選択された駒のy座標, 遷移先ファイル名, 問番号, ユーザ名数)
    */

    //画面構成
    print "<div class=\"grid\">\n";
    for($i = 1; $i <= MAX_X; $i++) {
      print "<div id=\"x$i\"><p>";
      bp_change($i);
      print "</p></div>\n";
      print "<div id=\"y$i\"><p>$i</p></div>\n";
    }

    $data0 = array($data_x, $data_y);
    mp_checkMove($Board, $data0, $data);

    $data[] = $data_x;
    $data[] = $data_y;
    $n = count($data) / 2;

    for($y = 0; $y < MAX_Y; $y++) {
      for($x = MAX_X - 1; $x >= 0; $x--) {
        for($i = 0; $i < $n; $i++) {
          if(($x == $data[2 * $i]) && ($y == $data[2 * $i + 1])) {
            switch($Board[$x][$y]->getNameNum()) {
              case 1:
              case -1:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/ne_king.png\" usemap=\"#ne_king_$x$y\"></div>\n";
                  print "<map name=\"ne_king_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"KING\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid tomato;\"><img src=\"../ping/n_king.png\" usemap=\"#n_king_$x$y\"></div>\n";
                  print "<map name=\"n_king_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"KING\"></map>\n";
                }
                break;
              case 2:
              case -2:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/ne_king2.png\" usemap=\"#ne_king2_$x$y\"></div>\n";
                  print "<map name=\"ne_king2_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"GYOKU\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/n_king2.png\" usemap=\"#n_king2_$x$y\"></div>\n";
                  print "<map name=\"n_king2_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"GYOKU\"></map>\n";
                }
                break;
              case 3:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/ne_rook.png\" usemap=\"#ne_rook_$x$y\"></div>\n";
                  print "<map name=\"ne_rook_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"ROOK\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$x$y\"></div>\n";
                  print "<map name=\"n_rook_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"ROOK\"></map>\n";
                }
                break;
              case 4:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/ne_bishop.png\" usemap=\"#ne_bishop_$x$y\"></div>\n";
                  print "<map name=\"ne_bishop_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"BISHOP\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$x$y\"></div>\n";
                  print "<map name=\"n_bishop_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"BISHOP\"></map>\n";
                }
                break;
              case 5:
              case -5:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/ne_gold.png\" usemap=\"#ne_gold_$x$y\"></div>\n";
                  print "<map name=\"ne_gold_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"GOLD\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$x$y\"></div>\n";
                  print "<map name=\"n_gold_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"GOLD\"></map>\n";
                }
                break;
              case 6:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/ne_silver.png\" usemap=\"#ne_silver_$x$y\"></div>\n";
                  print "<map name=\"ne_silver_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"SILVER\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$x$y\"></div>\n";
                  print "<map name=\"n_silver_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"SILVER\"></map>\n";
                }
                break;
              case 7:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/ne_knight.png\" usemap=\"#ne_knight_$x$y\"></div>\n";
                  print "<map name=\"ne_knight_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"KNIGHT\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid tomato;\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$x$y\"></div>\n";
                  print "<map name=\"n_knight_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"KNIGHT\"></map>\n";
                }
                break;
              case 8:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/ne_lance.png\" usemap=\"#ne_lance_$x$y\"></div>\n";
                  print "<map name=\"ne_lance_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"LANCE\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$x$y\"></div>\n";
                  print "<map name=\"n_lance_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"LANCE\"></map>\n";
                }
                break;
              case 9:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/ne_pawn.png\" usemap=\"#ne_pawn_$x$y\"></div>\n";
                  print "<map name=\"ne_pawn_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"PAWN\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$x$y\"></div>\n";
                  print "<map name=\"n_pawn_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"PAWN\"></map>\n";
                }
                break;
              case -3:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/pe_rook.png\" usemap=\"#pe_rook_$x$y\"></div>\n";
                  print "<map name=\"pe_rook_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_ROOK\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/p_rook.png\" usemap=\"#p_rook_$x$y\"></div>\n";
                  print "<map name=\"p_rook_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_ROOK\"></map>\n";
                }
                break;
              case -4:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/pe_bishop.png\" usemap=\"#pe_bishop_$x$y\"></div>\n";
                  print "<map name=\"pe_bishop_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_BISHOP\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;><img src=\"../ping/p_bishop.png\" usemap=\"#p_bishop_$x$y\"></div>\n";
                  print "<map name=\"p_bishop_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_BISHOP\"></map>\n";
                }
                break;
              case -6:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/pe_silver.png\" usemap=\"#pe_silver_$x$y\"></div>\n";
                  print "<map name=\"pe_silver_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_SILVER\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/p_silver.png\" usemap=\"#p_silver_$x$y\"></div>\n";
                  print "<map name=\"p_silver_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_SILVER\"></map>\n";
                }
                break;
              case -7:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/pe_knight.png\" usemap=\"#pe_knight_$x$y\"></div>\n";
                  print "<map name=\"pe_knight_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_KNIGHT\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/p_knight.png\" usemap=\"#p_knight_$x$y\"></div>\n";
                  print "<map name=\"p_knight_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_KNIGHT\"></map>\n";
                }
                break;
              case -8:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/pe_lance.png\" usemap=\"#pe_lance_$x$y\"></div>\n";
                  print "<map name=\"pe_lance_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_LANCE\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/p_lance.png\" usemap=\"#p_lance_$x$y\"></div>\n";
                  print "<map name=\"p_lance_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_LANCE\"></map>\n";
                }
                break;
              case -9:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/pe_pawn.png\" usemap=\"#pe_pawn_$x$y\"></div>\n";
                  print "<map name=\"pe_pawn_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_PAWN\"></map>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\" style=\"border: 5px solid tomato;\"><img src=\"../ping/p_pawn.png\" usemap=\"#p_pawn_$x$y\"></div>\n";
                  print "<map name=\"p_pawn_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"P_PAWN\"></map>\n";
                }
                break;
              default:
                print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/null.png\" usemap=\"#null_$x$y\"></div>\n";
                print "<map name=\"null_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=$data_x&by=$data_y&uid=$uid\" alt=\"NULL\"></map>\n";
                break;
            }
            break;
          }
        }
        switch($Board[$x][$y]->getNameNum()) {
          case 1:
          case -1:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_king.png\" usemap=\"#ne_king_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_king.png\" usemap=\"#n_king_$x$y\"></div>\n";
            }
            break;
          case 2:
          case -2:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_king2.png\" usemap=\"#ne_king2_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_king2.png\" usemap=\"#n_king2_$x$y\"></div>\n";
            }
            break;
          case 3:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_rook.png\" usemap=\"#ne_rook_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$x$y\"></div>\n";
            }
            break;
            case 4:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_bishop.png\" usemap=\"#ne_bishop_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$x$y\"></div>\n";
            }
            break;
          case 5:
          case -5:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_gold.png\" usemap=\"#ne_gold_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$x$y\"></div>\n";
            }
            break;
          case 6:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_silver.png\" usemap=\"#ne_silver_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$x$y\"></div>\n";
            }
            break;
          case 7:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_knight.png\" usemap=\"#ne_knight_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$x$y\"></div>\n";
            }
            break;
          case 8:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_lance.png\" usemap=\"#ne_lance_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$x$y\"></div>\n";
            }
            break;
          case 9:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/ne_pawn.png\" usemap=\"#ne_pawn_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$x$y\"></div>\n";
            }
            break;
          case -3:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_rook.png\" usemap=\"#pe_rook_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_rook.png\" usemap=\"#p_rook_$x$y\"></div>\n";
            }
            break;
          case -4:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_bishop.png\" usemap=\"#pe_bishop_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_bishop.png\" usemap=\"#p_bishop_$x$y\"></div>\n";
            }
            break;
          case -6:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_silver.png\" usemap=\"#pe_silver_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_silver.png\" usemap=\"#p_silver_$x$y\"></div>\n";
            }
            break;
          case -7:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_knight.png\" usemap=\"#pe_knight_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_knight.png\" usemap=\"#p_knight_$x$y\"></div>\n";
            }
            break;
          case -8:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_lance.png\" usemap=\"#pe_lance_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_lance.png\" usemap=\"#p_lance_$x$y\"></div>\n";
            }
            break;
          case -9:
            if($Board[$x][$y]->getOrd() === ENEMY) {
              print "<div id=\"board$x$y\"><img src=\"../ping/pe_pawn.png\" usemap=\"#pe_pawn_$x$y\"></div>\n";
            }elseif($Board[$x][$y]->getOrd() === MYSELF) {
              print "<div id=\"board$x$y\"><img src=\"../ping/p_pawn.png\" usemap=\"#p_pawn_$x$y\"></div>\n";
            }
            break;
          default:
            print "<div id=\"board$x$y\"><img src=\"../ping/null.png\" usemap=\"#null_$x$y\"></div>\n";
            break;
        }
      }
    }
  }

  function bp_table_unselect(&$Table, $file, $id)
  {
    $n = count($Table);

    if($n == 0) {
      print "<div id=\"table\">持ち駒:なし</div>\n";
    }else {
      print "<div id=\"table\">持ち駒</div>\n";
    }
    for($i = 0; $i < $n; $i++) {
      switch($Table[$i]->getNameNum()) {
        case 3:
          print "<div id=\"table$i\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$i\"></div>\n";
          print "<map name=\"n_rook_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&id=$id&table=$i\" alt=\"ROOK\"></map>\n";
          break;
        case 4:
          print "<div id=\"table$i\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$i\"></div>\n";
          print "<map name=\"n_bishop_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&id=$id&table=$i\" alt=\"BISHOP\"></map>\n";
          break;
        case 5:
          print "<div id=\"table$i\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$i\"></div>\n";
          print "<map name=\"n_gold_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&id=$id&table=$i\" alt=\"GOLD\"></map>\n";
          break;
        case 6:
          print "<div id=\"table$i\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$i\"></div>\n";
          print "<map name=\"n_silver_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&id=$id&table=$i\" alt=\"SILVER\"></map>\n";
          break;
        case 7:
          print "<div id=\"table$i\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$i\"></div>\n";
          print "<map name=\"n_knight_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&id=$id&table=$i\" alt=\"KNIGHT\"></map>\n";
          break;
        case 8:
          print "<div id=\"table$i\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$i\"></div>\n";
          print "<map name=\"n_lance_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&id=$id&table=$i\" alt=\"LANCE\"></map>\n";
          break;
        case 9:
          print "<div id=\"table$i\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$i\"></div>\n";
          print "<map name=\"n_pawn_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&id=$id&table=$i\" alt=\"PAWN\"></map>\n";
          break;
        default :
          print "<div id=\"table$i\"><img src=\"../ping/null.png\" usemap=\"#null_$i\"></div>\n";
          print "<map name=\"null_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&id=$id&table=$i\" alt=\"error\"></map>\n";
          break;
      }
    }
  }

  function bp_table_select($Board, $Table, $table, $file, $token, $uid)
  {
    bp_print($Board);
    switch($Table[$table]->getNameNum()) {
      case 3:
      case 4:
      case 5:
      case 6:
        for($y = 0; $y  < MAX_Y; $y++) {
          for($x = MAX_X - 1; $x >= 0; $x--) {
            switch($Board[$x][$y]->getNameNum()) {
              case 1:
              case -1:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_king.png\" usemap=\"#ne_king_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_king.png\" usemap=\"#n_king_$x$y\"></div>\n";
                }
                break;
              case 2:
              case -2:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_king2.png\" usemap=\"#ne_king2_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_king2.png\" usemap=\"#n_king2_$x$y\"></div>\n";
                }
                break;
              case 3:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_rook.png\" usemap=\"#ne_rook_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$x$y\"></div>\n";
                }
                break;
              case 4:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_bishop.png\" usemap=\"#ne_bishop_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$x$y\"></div>\n";
                }
                break;
              case 5:
              case -5:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_gold.png\" usemap=\"#ne_gold_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$x$y\"></div>\n";
                }
                break;
              case 6:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_silver.png\" usemap=\"#ne_silver_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$x$y\"></div>\n";
                }
                break;
              case 7:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_knight.png\" usemap=\"#ne_knight_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$x$y\"></div>\n";
                }
                break;
              case 8:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_lance.png\" usemap=\"#ne_lance_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$x$y\"></div>\n";
                }
                break;
              case 9:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_pawn.png\" usemap=\"#ne_pawn_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$x$y\"></div>\n";
                }
                break;
              case -3:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_rook.png\" usemap=\"#pe_rook_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_rook.png\" usemap=\"#p_rook_$x$y\"></div>\n";
                }
                break;
              case -4:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_bishop.png\" usemap=\"#pe_bishop_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_bishop.png\" usemap=\"#p_bishop_$x$y\"></div>\n";
                }
                break;
              case -6:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_silver.png\" usemap=\"#pe_silver_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_silver.png\" usemap=\"#p_silver_$x$y\"></div>\n";
                }
                break;
              case -7:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_knight.png\" usemap=\"#pe_knight_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_knight.png\" usemap=\"#p_knight_$x$y\"></div>\n";
                }
                break;
              case -8:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_lance.png\" usemap=\"#pe_lance_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_lance.png\" usemap=\"#p_lance_$x$y\"></div>\n";
                }
                break;
              case -9:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_pawn.png\" usemap=\"#pe_pawn_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_pawn.png\" usemap=\"#p_pawn_$x$y\"></div>\n";
                }
                break;
              default:
                print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/null.png\" usemap=\"#null_$x$y\"></div>\n";
                print "<map name=\"null_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=-1&by=-1&table=$table&token=$token&uid=$uid\" alt=\"NULL\"></map>\n";
            }
          }
        }
        break;
      case 7:
        for($y = 2; $y  < MAX_Y; $y++) {
          for($x = MAX_X - 1; $x >= 0; $x--) {
            switch($Board[$x][$y]->getNameNum()) {
              case 1:
              case -1:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_king.png\" usemap=\"#ne_king_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_king.png\" usemap=\"#n_king_$x$y\"></div>\n";
                }
                break;
              case 2:
              case -2:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_king2.png\" usemap=\"#ne_king2_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_king2.png\" usemap=\"#n_king2_$x$y\"></div>\n";
                }
                break;
              case 3:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_rook.png\" usemap=\"#ne_rook_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$x$y\"></div>\n";
                }
                break;
              case 4:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_bishop.png\" usemap=\"#ne_bishop_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$x$y\"></div>\n";
                }
                break;
              case 5:
              case -5:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_gold.png\" usemap=\"#ne_gold_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$x$y\"></div>\n";
                }
                break;
              case 6:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_silver.png\" usemap=\"#ne_silver_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$x$y\"></div>\n";
                }
                break;
              case 7:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_knight.png\" usemap=\"#ne_knight_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$x$y\"></div>\n";
                }
                break;
              case 8:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_lance.png\" usemap=\"#ne_lance_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$x$y\"></div>\n";
                }
                break;
              case 9:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_pawn.png\" usemap=\"#ne_pawn_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$x$y\"></div>\n";
                }
                break;
              case -3:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_rook.png\" usemap=\"#pe_rook_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_rook.png\" usemap=\"#p_rook_$x$y\"></div>\n";
                }
                break;
              case -4:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_bishop.png\" usemap=\"#pe_bishop_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_bishop.png\" usemap=\"#p_bishop_$x$y\"></div>\n";
                }
                break;
              case -6:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_silver.png\" usemap=\"#pe_silver_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_silver.png\" usemap=\"#p_silver_$x$y\"></div>\n";
                }
                break;
              case -7:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_knight.png\" usemap=\"#pe_knight_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_knight.png\" usemap=\"#p_knight_$x$y\"></div>\n";
                }
                break;
              case -8:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_lance.png\" usemap=\"#pe_lance_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_lance.png\" usemap=\"#p_lance_$x$y\"></div>\n";
                }
                break;
              case -9:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_pawn.png\" usemap=\"#pe_pawn_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_pawn.png\" usemap=\"#p_pawn_$x$y\"></div>\n";
                }
                break;
              default:
                print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/null.png\" usemap=\"#null_$x$y\"></div>\n";
                print "<map name=\"null_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=-1&by=-1&table=$table&token=$token&uid=$uid\" alt=\"NULL\"></map>\n";
            }
          }
        }
        break;
      case 8:
      case 9:
        for($y = 1; $y  < MAX_Y; $y++) {
          for($x = MAX_X - 1; $x >= 0; $x--) {
            switch($Board[$x][$y]->getNameNum()) {
              case 1:
              case -1:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_king.png\" usemap=\"#ne_king_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_king.png\" usemap=\"#n_king_$x$y\"></div>\n";
                }
                break;
              case 2:
              case -2:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_king2.png\" usemap=\"#ne_king2_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_king2.png\" usemap=\"#n_king2_$x$y\"></div>\n";
                }
                break;
              case 3:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_rook.png\" usemap=\"#ne_rook_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$x$y\"></div>\n";
                }
                break;
              case 4:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_bishop.png\" usemap=\"#ne_bishop_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$x$y\"></div>\n";
                }
                break;
              case 5:
              case -5:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_gold.png\" usemap=\"#ne_gold_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$x$y\"></div>\n";
                }
                break;
              case 6:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_silver.png\" usemap=\"#ne_silver_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$x$y\"></div>\n";
                }
                break;
              case 7:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_knight.png\" usemap=\"#ne_knight_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$x$y\"></div>\n";
                }
                break;
              case 8:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_lance.png\" usemap=\"#ne_lance_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$x$y\"></div>\n";
                }
                break;
              case 9:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/ne_pawn.png\" usemap=\"#ne_pawn_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$x$y\"></div>\n";
                }
                break;
              case -3:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_rook.png\" usemap=\"#pe_rook_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_rook.png\" usemap=\"#p_rook_$x$y\"></div>\n";
                }
                break;
              case -4:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_bishop.png\" usemap=\"#pe_bishop_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_bishop.png\" usemap=\"#p_bishop_$x$y\"></div>\n";
                }
                break;
              case -6:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_silver.png\" usemap=\"#pe_silver_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_silver.png\" usemap=\"#p_silver_$x$y\"></div>\n";
                }
                break;
              case -7:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_knight.png\" usemap=\"#pe_knight_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_knight.png\" usemap=\"#p_knight_$x$y\"></div>\n";
                }
                break;
              case -8:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_lance.png\" usemap=\"#pe_lance_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_lance.png\" usemap=\"#p_lance_$x$y\"></div>\n";
                }
                break;
              case -9:
                if($Board[$x][$y]->getOrd() === ENEMY) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/pe_pawn.png\" usemap=\"#pe_pawn_$x$y\"></div>\n";
                }elseif($Board[$x][$y]->getOrd() === MYSELF) {
                  print "<div id=\"board$x$y\"><img src=\"../ping/p_pawn.png\" usemap=\"#p_pawn_$x$y\"></div>\n";
                }
                break;
              default:
                print "<div id=\"board$x$y\" style=\"border: 3px solid orange;\"><img src=\"../ping/null.png\" usemap=\"#null_$x$y\"></div>\n";
                print "<map name=\"null_$x$y\"><area shape=\"default\" href=\"$file?x=$x&y=$y&bx=-1&by=-1&table=$table&token=$token&uid=$uid\" alt=\"NULL\"></map>\n";
            }
          }
        }
        break;
    }
    for($i = 0; $i < count($Table); $i++) {
      if($i == $table) {
        switch($Table[$i]->getNameNum()) {
          case 3:
            print "<div id=\"table$i\" style=\"border: 3px solid tomato;\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$i\"></div>\n";
            print "<map name=\"n_rook_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&bx=-1&by=-1&uid=$uid&table=$i\" alt=\"ROOK\"></map>\n";
            break;
          case 4:
            print "<div id=\"table$i\" style=\"border: 3px solid tomato;\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$i\"></div>\n";
            print "<map name=\"n_bishop_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&bx=-1&by=-1&uid=$uid&table=$i\" alt=\"BISHOP\"></map>\n";
            break;
          case 5:
            print "<div id=\"table$i\" style=\"border: 3px solid tomato;\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$i\"></div>\n";
            print "<map name=\"n_gold_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&&bx=-1&by=-1&uid=$uid&table=$i\" alt=\"GOLD\"></map>\n";
            break;
          case 6:
            print "<div id=\"table$i\" style=\"border: 3px solid tomato;\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$i\"></div>\n";
            print "<map name=\"n_silver_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&bx=-1&by=-1&uid=$uid&table=$i\" alt=\"SILVER\"></map>\n";
            break;
          case 7:
            print "<div id=\"table$i\" style=\"border: 3px solid tomato;\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$i\"></div>\n";
            print "<map name=\"n_knight_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&bx=-1&by=-1&uid=$uid&table=$i\" alt=\"KNIGHT\"></map>\n";
            break;
          case 8:
            print "<div id=\"table$i\" style=\"border: 3px solid tomato;\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$i\"></div>\n";
            print "<map name=\"n_lance_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&bx=-1&by=-1&uid=$uid&table=$i\" alt=\"LANCE\"></map>\n";
            break;
          case 9:
            print "<div id=\"table$i\" style=\"border: 3px solid tomato;\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$i\"></div>\n";
            print "<map name=\"n_pawn_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&bx=-1&by=-1&uid=$uid&table=$i\" alt=\"PAWN\"></map>\n";
            break;
          default :
            print "<div id=\"table$i\"><img src=\"../ping/null.png\" usemap=\"#null_$i\"></div>\n";
            print "<map name=\"null_$i\"><area shape=\"default\" href=\"$file?x=-1&y=-1&bx=-1&by=-1&uid=$uid&table=$i\" alt=\"error\"></map>\n";
            break;
        }
      }else {
        switch($Table[$i]->getNameNum()) {
          case 3:
            print "<div id=\"table$i\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$i\"></div>\n";
            break;
          case 4:
            print "<div id=\"table$i\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$i\"></div>\n";
            break;
          case 5:
            print "<div id=\"table$i\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$i\"></div>\n";
            break;
          case 6:
            print "<div id=\"table$i\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$i\"></div>\n";
            break;
          case 7:
            print "<div id=\"table$i\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$i\"></div>\n";
            break;
          case 8:
            print "<div id=\"table$i\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$i\"></div>\n";
            break;
          case 9:
            print "<div id=\"table$i\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$i\"></div>\n";
            break;
          default :
            print "<div id=\"table$i\"><img src=\"../ping/null.png\" usemap=\"#null_$i\"></div>\n";
            break;
        }
      }
    }
  }

  function bp_table_print(&$Table)
  {
    $n = count($Table);

    if($n == 0) {
      print "<div id=\"table\">持ち駒:なし</div>\n";
    }else {
      print "<div id=\"table\">持ち駒</div>\n";
    }
    for($i = 0; $i < $n; $i++) {
      switch($Table[$i]->getNameNum()) {
        case 3:
          print "<div id=\"table$i\"><img src=\"../ping/n_rook.png\" usemap=\"#n_rook_$i\"></div>\n";
          break;
        case 4:
          print "<div id=\"table$i\"><img src=\"../ping/n_bishop.png\" usemap=\"#n_bishop_$i\"></div>\n";
          break;
        case 5:
          print "<div id=\"table$i\"><img src=\"../ping/n_gold.png\" usemap=\"#n_gold_$i\"></div>\n";
          break;
        case 6:
          print "<div id=\"table$i\"><img src=\"../ping/n_silver.png\" usemap=\"#n_silver_$i\"></div>\n";
          break;
        case 7:
          print "<div id=\"table$i\"><img src=\"../ping/n_knight.png\" usemap=\"#n_knight_$i\"></div>\n";
          break;
        case 8:
          print "<div id=\"table$i\"><img src=\"../ping/n_lance.png\" usemap=\"#n_lance_$i\"></div>\n";
          break;
        case 9:
          print "<div id=\"table$i\"><img src=\"../ping/n_pawn.png\" usemap=\"#n_pawn_$i\"></div>\n";
          break;
        default :
          print "<div id=\"table$i\"><img src=\"../ping/null.png\" usemap=\"#null_$i\"></div>\n";
          break;
      }
    }
  }
?>
