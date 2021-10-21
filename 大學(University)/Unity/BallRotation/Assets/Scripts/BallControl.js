#pragma strict
var balls : Sprite[] ;
var ballPos : Vector3[] ;
var allBall : Ball[] ;

function Start(){
  SpawnRandomBall() ;
  SavePosition() ;
  SaveBall() ;
}

function Update(){
  if(Input.GetKeyDown(KeyCode.Q)){
    Application.LoadLevel(Application.loadedLevel) ;
  }
}

function SpawnRandomBall(){
  for(var child : SpriteRenderer in GetComponentsInChildren.<SpriteRenderer>()){
    if(child.transform == transform){
      continue ; //跳過迴圈一次
    }
    child.sprite = balls[Random.Range(0,3)] ;
    
  }
}

function AllCheckLink(){
  for(var b:Ball in allBall){
    b.CheckLink() ;
  }
}

function AllCheckFall(){
	for(var i=29 ; i>=-29 ; i--){
    for(var b:Ball in allBall){
      if(b.id == i){
      	b.CheckFall() ;
      }
    }
  }
}

function SavePosition(){
  ballPos = new Vector3[30] ;
  
  for(var i=0 ;i<transform.childCount ; i++){
    ballPos[i] = transform.GetChild(i).position ;
  }
}

function SaveBall(){
  allBall = new Ball[30] ;
  allBall = GetComponentsInChildren.<Ball>() ;
}
// new
function ResetBalls(){

}
