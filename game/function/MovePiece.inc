<!--67200072 宇佐見聡涼-->
<?php
  function mp_checkMove($Board, $point, &$data)
  {
    /*
    選択した駒が移動できる座標を配列で返す関数配列の2n番目がx座標,2n+1番目がy座標(nは0から始まる正の整数)
    行ける座標が入った一次配列mp_checkMove(盤面の情報を入れた配列, 調べたい駒のx座標が0番,y座標1番に入った配列)
    */
    list($x, $y) = $point;
    $ord = $Board[$x][$y]->getOrd();

    switch($Board[$x][$y]->getNameNum()) {
      case 1:
      case 2:
      case -1:
      case -2:
        if($y > 0 && $Board[$x][$y - 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y - 1;
        }
        if($y > 0 && $x  < MAX_X - 1 && $Board[$x + 1][$y - 1]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y - 1;
        }
        if($x < MAX_X - 1 && $Board[$x + 1][$y]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y;
        }
        if($y < MAX_Y - 1 && $x < MAX_X - 1 && $Board[$x + 1][$y + 1]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y + 1;
        }
        if($y < MAX_Y - 1 && $Board[$x][$y + 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y + 1;
        }
        if($y < MAX_Y - 1 && $x > 0 && $Board[$x - 1][$y + 1]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y + 1;
        }
        if($x > 0 && $Board[$x - 1][$y]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y;
        }
        if($y > 0 && $x > 0 && $Board[$x - 1][$y - 1]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y - 1;
        }
        break;

      case -3:
        if($y > 0 && $x  < MAX_X - 1 && $Board[$x + 1][$y - 1]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y - 1;
        }
        if($y < MAX_Y - 1 && $x < MAX_X - 1 && $Board[$x + 1][$y + 1]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y + 1;
        }
        if($y < MAX_Y - 1 && $x > 0 && $Board[$x - 1][$y + 1]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y + 1;
        }
        if($y > 0 && $x > 0 && $Board[$x - 1][$y - 1]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y - 1;
        }

      case 3:
        while($y > 0 && $Board[$x][$y - 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y - 1;
          if($Board[$x][$y - 1]->getOrd() === ENEMY) break;
          $y--;
        }
        list($x, $y) = $point;
        while($x < MAX_X - 1 && $Board[$x + 1][$y]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y;
          if($Board[$x + 1][$y]->getOrd() === ENEMY) break;
          $x++;
        }
        list($x, $y) = $point;
        while($y < MAX_Y - 1 && $Board[$x][$y + 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y + 1;
          if($Board[$x][$y + 1]->getOrd() === ENEMY) break;
          $y++;
        }
        list($x, $y) = $point;
        while($x > 0 && $Board[$x - 1][$y]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y;
          if($Board[$x - 1][$y]->getOrd() === ENEMY) break;
          $x--;
        }
        break;

      case -4:
        if($y > 0 && $Board[$x][$y - 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y - 1;
        }
        if($x < MAX_X - 1 && $Board[$x + 1][$y]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y;
        }
        if($y < MAX_Y - 1 && $Board[$x][$y + 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y + 1;
        }
        if($x > 0 && $Board[$x - 1][$y]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y;
        }

      case 4:
        while($y > 0 && $x < MAX_X - 1 && $Board[$x + 1][$y - 1]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y - 1;
          if($Board[$x + 1][$y - 1]->getOrd() === ENEMY) break;
          $x++;
          $y--;
        }
        list($x, $y) = $point;
        while($y < MAX_Y - 1 && $x < MAX_X - 1 && $Board[$x + 1][$y + 1]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y + 1;
          if($Board[$x + 1][$y + 1]->getOrd() === ENEMY) break;
          $x++;
          $y++;
        }
        list($x, $y) = $point;
        while($y < MAX_Y - 1 && $x > 0 && $Board[$x - 1][$y + 1]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y + 1;
          if($Board[$x - 1][$y + 1]->getOrd() === ENEMY) break;
          $x--;
          $y++;
        }
        list($x, $y) = $point;
        while($y > 0 && $x > 0 && $Board[$x - 1][$y - 1]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y - 1;
          if($Board[$x - 1][$y - 1]->getOrd() === ENEMY) break;
          $x--;
          $y--;
        }
        break;

      case 5:
      case -5:
      case -6:
      case -7:
      case -8:
      case -9:
        if($y > 0 && $Board[$x][$y - 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y - 1;
        }
        if($y > 0 && $x  < MAX_X - 1 && $Board[$x + 1][$y - 1]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y - 1;
        }
        if($x < MAX_X - 1 && $Board[$x + 1][$y]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y;
        }
        if($y < MAX_Y - 1 && $Board[$x][$y + 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y + 1;
        }
        if($x > 0 && $Board[$x - 1][$y]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y;
        }
        if($y > 0 && $x > 0 && $Board[$x - 1][$y - 1]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y - 1;
        }
        break;

      case 6:
        if($y > 0 && $Board[$x][$y - 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y - 1;
        }
        if($y > 0 && $x < MAX_X - 1 && $Board[$x + 1][$y - 1]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y - 1;
        }
        if($y < MAX_Y - 1 && $x < MAX_X - 1 && $Board[$x + 1][$y + 1]->getOrd() !== $ord) {
          $data[] = $x + 1;
          $data[] = $y + 1;
        }
        if($y < MAX_Y - 1 && $x > 0 && $Board[$x - 1][$y + 1]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y + 1;
        }
        if($y > 0 && $x > 0 && $Board[$x - 1][$y - 1]->getOrd() !== $ord) {
          $data[] = $x - 1;
          $data[] = $y - 1;
        }
        break;

      case 7:
        if($y > 1 && $x < MAX_X - 1) {
          if($Board[$x + 1][$y - 2]->getOrd() !== $ord) {
            $data[] = $x + 1;
            $data[] = $y - 2;
          }
        }
        if($y > 1 && $x > 0) {
          if($Board[$x - 1][$y - 2]->getOrd() !== $ord) {
            $data[] = $x - 1;
            $data[] = $y - 2;
          }
        }
        break;

      case 8:
        while($y > 0 && $Board[$x][$y - 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y - 1;
          if($Board[$x][$y - 1]->getOrd() === ENEMY) break;
          $y--;
        }
        break;

      case 9:
        if($y > 0 && $Board[$x][$y - 1]->getOrd() !== $ord) {
          $data[] = $x;
          $data[] = $y - 1;
        }
        break;

      default:
        $data = false;
        break;
    }

    return true;
  }

  function mp_swap(&$before, &$after)
  {
    /*
    2つの座標の駒を入れ替える.移動元の駒がない場合移動元は駒情報を消す
    mp_swap(移動元, 移動先)
    */
    if($before->getOrd() == NONE) return ;
    $tmp = $before;
    $before = $after;
    $after = $tmp;
    $before->setAll(0, 0);
  }

  function mp_checkProm($x, $y, $bx, $by, $piece, $Filename, $u_name)
  {
    /*
    成るかどうか確認するフォームを表示
    mp_checkProm(選択した駒の移動後x座標, 選択した駒の移動後y座標, 選択した駒の移動前x座標, 選択した駒の移動前y座標, 選択した駒の数字, 遷移先ファイル名)
    */

    if($y < 3 && $piece > 0) {
      //画面構成
      print "<div class=\"grid\">\n";

      switch($piece) {
        case 3:
        case 4:
        case 6:
          print  <<< EOL
  <div class="prom"><form action="{$Filename}" method="post">
  <p>成りますか?</p>
  <p>
  <input type="radio" name="prom" value="1" id="prom">
  <label for="prom">成る</label>
  <input type="radio" name="prom" value="0" id="nprom">
  <label for="nprom">成らない</label>
  <input type="hidden" name="x" value="{$x}">
  <input type="hidden" name="y" value="{$y}">
  <input type="hidden" name="bx" value="{$bx}">
  <input type="hidden" name="by" value="{$by}">
  <input type="hidden" name="uid" value="{$u_name}">
  </p>
  <p><input type="submit" value="送信" class="submit"></p>
  </form></div>
EOL;
          break;
        case 7:
        if($y == 0 || $y == 1) {
          print <<< EOL1
<div class="prom"><form action="{$Filename}" method="post">
<p>成ります</p>
<p>
<input type="hidden" name="prom" value="1">
<input type="hidden" name="x" value="{$x}">
<input type="hidden" name="y" value="{$y}">
<input type="hidden" name="bx" value="{$bx}">
<input type="hidden" name="by" value="{$by}">
<input type="hidden" name="uid" value="{$u_name}">
</p>
<p><input type="submit" value="確認" class="submit"></p>
</form></div>
EOL1;
          break;
        }else {
          print  <<< EOL2
<div class="prom"><form action="{$Filename}" method="post">
<p>成りますか?</p>
<p>
<input type="radio" name="prom" value="1" id="prom">
<label for="prom">成る</label>
<input type="radio" name="prom" value="0" id="nprom">
<label for="nprom">成らない</label>
<input type="hidden" name="x" value="{$x}">
<input type="hidden" name="y" value="{$y}">
<input type="hidden" name="bx" value="{$bx}">
<input type="hidden" name="by" value="{$by}">
<input type="hidden" name="uid" value="{$u_name}">
</p>
<p><input type="submit" value="送信" class="submit"></p>
</form></div>
EOL2;
      break;
        }
        case 8:
        case 9:
          if($y == 0) {
            print <<< EOL3
  <div class="prom"><form action="{$Filename}" method="post">
  <p>成ります</p>
  <p>
  <input type="hidden" name="prom" value="1">
  <input type="hidden" name="x" value="{$x}">
  <input type="hidden" name="y" value="{$y}">
  <input type="hidden" name="bx" value="{$bx}">
  <input type="hidden" name="by" value="{$by}">
  <input type="hidden" name="uid" value="{$u_name}">
  </p>
  <p><input type="submit" value="確認" class="submit"></p>
  </form></div>
EOL3;
  break;
          }else {
            print  <<< EOL4
  <div class="prom"><form action="{$Filename}" method="post">
  <p>成りますか?</p>
  <p>
  <input type="radio" name="prom" value="1" id="prom">
  <label for="prom">成る</label>
  <input type="radio" name="prom" value="0" id="nprom">
  <label for="nprom">成らない</label>
  <input type="hidden" name="x" value="{$x}">
  <input type="hidden" name="y" value="{$y}">
  <input type="hidden" name="bx" value="{$bx}">
  <input type="hidden" name="by" value="{$by}">
  <input type="hidden" name="uid" value="{$u_name}">
  </p>
  <p><input type="submit" value="送信" class="submit"></p>
  </form></div>
EOL4;
          }
        default:
          break;
      }
      return 1;
    }
    return 0;
  }

  function mp_CheckMate($Board)
  {
    /*
    王手判定.戻り値が1なら詰み
    戻り値 = mp_check(盤面情報)
    */
    $temp_board = mp_copy($Board);
    $position = array(); //王の座標
    $flg = 0;


    //敵王の座標取得
    for($y = 0; $y < MAX_Y; $y++) {
      for($x = MAX_X - 1; $x >= 0; $x--) {
        if(($Board[$x][$y]->getNameNum() == 1 || $Board[$x][$y]->getNameNum() == -1) && $Board[$x][$y]->getOrd() == ENEMY) {
          array_push($position, $x, $y);
          $flg = 1;
          break;
        }
        if($flg == 1) break;
      }
    }
    mp_checkMove($Board, $position, $data); //王の移動できる座標
    array_merge($data, $position);
    $N = count($data) / 2; //王の移動できる座標数
    $flg = 0;


    for($i = 0; $i < $N; $i++) {
      $cnt = array($data[2 * $i], $data[2 * $i + 1]);
      mp_swap($temp_board[$position[0]][$position[1]], $temp_board[$data[2 * $i]][$data[2 * $i + 1]]);
      #print $data[2 * $i].",".$data[2 * $i + 1].":";
      #print "[{$temp_board[$data[2 * $i]][$data[2 * $i + 1]]->getName()}]\n";
      #print $position[0].",".$position[1].":[{$temp_board[$position[0]][$position[1]]->getName()}]\n";
      $flg += mp_check($temp_board, array($data[2 * $i], $data[2 * $i + 1]));
      #print "\nflg:$flg\tN:$N\n";
      $temp_board = mp_copy($Board);
    }
    if($N == $flg) {
      return 1;
    }else {
      return 0;
    }
  }

  function mp_check($Board, $position)
  {
    /*
    王手を判定する.戻り値が1だと王手状態
    mp_check(盤面の情報の入った配列, 王の座標の入った配列)
    */
    /*
    print "六五四三二一\n";
    for($i = 0; $i < MAX_Y; $i++) {
      for($j = MAX_X - 1; $j >= 0; $j--) {
        print $Board[$j][$i]->getName();
      }
      $aaa = $j + 1;
      print $aaa."\n";
    }
    print "\n\n";
    */

    for($y = 0; $y < MAX_Y; $y++) {
      for($x = MAX_X - 1; $x >= 0; $x--) {
        if($Board[$x][$y]->getOrd() == MYSELF) {
          mp_checkMove($Board, Array($x, $y), $tmp); //自駒すべてが移動できる座標
          $n = count($tmp) / 2; //自駒すべてが移動できる座標数

          for($i = 0; $i < $n; $i++) {
            if(isset($position) && ($position[0] == $tmp[2 * $i] && $position[1] == $tmp[2 * $i + 1])) {
              /*王手判定*/
              unset($position);
              return 1;
            }
          }
        }
      }
    }
    return 0;
  }

  function mp_copy($Board)
  {
    /*
    盤面をコピーする．戻り値にコピーざれたものか帰る
    mp_copy(コピーしたい盤面)
    */
    for($y = 0; $y < MAX_Y; $y++) {
      for($x = 0; $x <MAX_X; $x++) {
        $temp_board[$x][$y] = clone $Board[$x][$y];
      }
    }
    return $temp_board;
  }
?>
