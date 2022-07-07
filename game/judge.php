<!--67200072 宇佐見聡涼-->
<?php
  function judge($data_bx, $data_by, $data_x, $data_y, $u_name, $q_id)
  {
    $sql = "select x, y, bx, by, name from answer where id = $q_id";
    @$result = da_query($sql);
    $data = pg_fetch_all($result);
    $next_id = $q_id + 1;
    @$result = da_query("select * from question where id = $next_id");
    $flg = pg_num_rows($result);

    if($data_bx == -1 && $data_by == -1) {
      if($data_bx == $data[0]['bx'] && $data_by == $data[0]['by'] && $data_x + 1 == $data[0]['x'] && $data_y + 1 == $data[0]['y']) {
        @$result = da_query("select * from $u_name where id = $q_id");
        $ID = pg_num_rows($result);
        if($ID == 0) da_query("insert into $u_name values($q_id)");
        print "<h2 class=\"judge\">正解!</h2>\n";
        print "<div class=\"title\">\n<form action=\"../index.html\"><p><input type=\"submit\" value=\"タイトル画面に戻る\"></p></form></div>\n";
        print "<div class=\"select\"><form action=\"select.php\" method=\"post\"><p><input type=\"submit\" value=\"難易度選択\"></p>\n<input type=\"hidden\" name=\"u_name\" value=\"$u_name\"></form></div>\n";
        if($flg != 0) print "<div class=\"next\"><form action=\"./main1.php\" method=\"post\"><p><input type=\"submit\" value=\"次の問題\"></p>\n<input type=\"hidden\" name=\"u_name\" value=\"$u_name\">\n<input type=\"hidden\" name=\"number\" value=\"$next_id\"></form>\n</div>";
        exit;
      }else {
        print "<h2 class=\"judge\">不正解!</h2>\n";
        print "<div class=\"title\">\n<form action=\"../index.html\"><p><input type=\"submit\" value=\"タイトル画面に戻る\"></p></form></div>\n";
        print "<div class=\"select\"><form action=\"select.php\" method=\"post\"><p><input type=\"submit\" value=\"難易度選択\"></p>\n<input type=\"hidden\" name=\"u_name\" value=\"$u_name\"></form></div>\n";
        print "<div class=\"next\"><form action=\"./main1.php\" method=\"post\"><p><input type=\"submit\" value=\"もう一度\"></p>\n<input type=\"hidden\" name=\"u_name\" value=\"$u_name\">\n<input type=\"hidden\" name=\"number\" value=\"$q_id\"></form>\n</div>";
        exit;
      }
    }else {
      if($data_bx + 1 == $data[0]['bx'] && $data_by + 1 == $data[0]['by'] && $data_x + 1 == $data[0]['x'] && $data_y + 1 == $data[0]['y']) {
        @$result = da_query("select * from $u_name where id = $q_id");
        $ID = pg_num_rows($result);
        if($ID == 0) da_query("insert into $u_name values($q_id)");
        print "<h2 class=\"judge\">正解!</h2>\n";
        print "<div class=\"title\">\n<form action=\"../index.html\"><p><input type=\"submit\" value=\"タイトル画面に戻る\"></p></form></div>\n";
        print "<div class=\"select\"><form action=\"select.php\" method=\"post\"><p><input type=\"submit\" value=\"難易度選択\"></p>\n<input type=\"hidden\" name=\"u_name\" value=\"$u_name\"></form></div>\n";
        if($flg != 0) print "<div class=\"next\"><form action=\"./main1.php\" method=\"post\"><p><input type=\"submit\" value=\"次の問題\"></p>\n<input type=\"hidden\" name=\"u_name\" value=\"$u_name\">\n<input type=\"hidden\" name=\"number\" value=\"$next_id\"></form>\n</div>";
        exit;
      }else {
        print "<h2 class=\"judge\">不正解!</h2>\n";
        print "<div class=\"title\">\n<form action=\"../index.html\"><p><input type=\"submit\" value=\"タイトル画面に戻る\"></p></form></div>\n";
        print "<div class=\"select\"><form action=\"select.php\" method=\"post\"><p><input type=\"submit\" value=\"難易度選択\"></p>\n<input type=\"hidden\" name=\"u_name\" value=\"$u_name\"></form></div>\n";
        print "<div class=\"next\"><form action=\"./main1.php\" method=\"post\"><p><input type=\"submit\" value=\"もう一度\"></p>\n<input type=\"hidden\" name=\"u_name\" value=\"$u_name\">\n<input type=\"hidden\" name=\"number\" value=\"$q_id\"></form>\n</div>";
        exit;
      }
    }
  }
?>
