<!--67200072 宇佐見聡涼-->
<?php
  class PieceName {
    /*
    基本使用しない
    */
    #0:なし, 1:王, 2:玉, 3:飛車, 4:角行, 5:金将, 6:銀将, 7:桂馬, 8:香車, 9:歩兵
    private $NormName = array("　", "王", "玉", "飛", "角", "金", "銀", "桂", "香", "歩");
    private $PromName = array("　", "王", "玉", "龍", "馬", "金", "全", "圭", "杏", "と");

    protected function NameTrans($name) {
      if($name > 0) {
        return  $this->NormName[$name];
      }else {
        return $this->PromName[$name * -1];
      }
    }
  }

  class PieceData extends PieceName {
    /*
    駒情報を保持する.詳しくは「php クラス」で検索推奨
    変数名->setAll(駒名を表す数字, 駒が自分か相手かを表す定数) 入れた駒の情報が記録される.これをしなければデフォルトでは駒がないものとして処理される
    変数名->getName() 記録されている駒の名前が返される
    変数名->getNameNum() 記録されている表す数字が返される
    変数名->getOrd() 記録されている駒が敵駒か自駒か駒がないかを表す定数が返される
    変数名->setProm() 記録させている駒がなっていない場合成る
    */
    private $name;
    private $ord;

    public function __construct($N, $O) {
      $this->name = $N;
      switch($O) {
        case ENEMY:
          $this->ord = ENEMY;
          return ;
        case MYSELF:
          $this->ord = MYSELF;
          return ;
        case NONE:
          $this->ord = NONE;
          return ;
      }
      return false;
    }
    public function getName() {
      return $this->NameTrans($this->name);
    }
    public function getNameNum() {
      return $this->name;
    }
    public function getOrd() {
      return $this->ord;
    }
    public function setProm() {
      if($this->name > 0) {
        $this->name *= -1;
        return ;
      }
    }
    public function setAll($N, $O) {
      $this->name = $N;
      switch($O) {
        case ENEMY:
          $this->ord = ENEMY;
          return ;
        case MYSELF:
          $this->ord = MYSELF;
          return ;
        case NONE:
          $this->ord = NONE;
          return ;
      }
      return false;
    }
  }

?>
