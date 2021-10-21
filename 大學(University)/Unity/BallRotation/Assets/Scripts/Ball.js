#pragma strict
var id : int = 0 ;
var control : BallControl ;
var move : boolean = false ;

function Awake(){
  control = transform.parent.GetComponent.<BallControl>() ;
}

function Update(){
  if(move){
    transform.position = Vector3.MoveTowards(transform.position, control.ballPos[id], 0.15) ;
    if(transform.position == control.ballPos[id]){
      move = false ;
    }
  }
}

function OnMouseDrag(){
  var cam : Camera = Camera.main ;
  var newPos : Vector3 = cam.ScreenToWorldPoint(Input.mousePosition) ;
  var bound : Bounds = transform.parent.GetComponent.<BoxCollider>().bounds ;
  var min : Vector3 = bound.min ;
  var max : Vector3 = bound.max ;
  
  newPos = Vector3(Mathf.Clamp(newPos.x, min.x, max.x), Mathf.Clamp(newPos.y, min.y, max.y), 0) ;
  
  transform.position = Vector3(newPos.x,newPos.y,0) ;
}

function OnMouseUp(){
  transform.position = control.ballPos[id] ;
  control.AllCheckLink() ;
  yield WaitForSeconds(0.6) ;
  control.AllCheckFall() ;
}

function CheckLink(){
  var hitsR : RaycastHit2D[] = Physics2D.LinecastAll(transform.position, transform.position+transform.right*10, 1<<8) ;
  var hitsL : RaycastHit2D[] = Physics2D.LinecastAll(transform.position, transform.position-transform.right*10, 1<<8) ;
  var hitsU : RaycastHit2D[] = Physics2D.LinecastAll(transform.position, transform.position+transform.up*10, 1<<8) ;
  var hitsB : RaycastHit2D[] = Physics2D.LinecastAll(transform.position, transform.position-transform.up*10, 1<<8) ;
  
  var sprite : Sprite = GetComponent.<SpriteRenderer>().sprite ;
  var horCount : int = 0 ;
  var verCount : int = 0 ;
  
  for(var i=0 ; i<hitsR.length ; i++){
    if(hitsR[i].collider.GetComponent.<SpriteRenderer>().sprite != sprite){
      break ;
    }
    horCount ++ ;
  }
  for(i=0 ; i<hitsL.length ; i++){
    if(hitsL[i].collider.GetComponent.<SpriteRenderer>().sprite != sprite){
      break ;
    }
    horCount ++ ;
  }
  for(i=0 ; i<hitsU.length ; i++){
    if(hitsU[i].collider.GetComponent.<SpriteRenderer>().sprite != sprite){
      break ;
    }
    verCount ++ ;
  }
  for(i=0 ; i<hitsB.length ; i++){
    if(hitsB[i].collider.GetComponent.<SpriteRenderer>().sprite != sprite){
      break ;
    }
    verCount ++ ;
  }
  
  horCount -- ;
  verCount -- ;
  
  if(horCount >= 3){
    for(var hit : RaycastHit2D in hitsR){
      if(hit.collider.GetComponent.<SpriteRenderer>().sprite == sprite){
        hit.collider.GetComponent.<Ball>().Fade() ;
      }else{
        break ;
      }
    }
    for(var hit : RaycastHit2D in hitsL){
      if(hit.collider.GetComponent.<SpriteRenderer>().sprite == sprite){
        hit.collider.GetComponent.<Ball>().Fade() ;
      }else{
        break ;
      }
    }
  }
  
  if(verCount >= 3){
    for(var hit : RaycastHit2D in hitsU){
      if(hit.collider.GetComponent.<SpriteRenderer>().sprite == sprite){
        hit.collider.GetComponent.<Ball>().Fade() ;
      }else{
        break ;
      }
    }
    for(var hit : RaycastHit2D in hitsB){
      if(hit.collider.GetComponent.<SpriteRenderer>().sprite == sprite){
        hit.collider.GetComponent.<Ball>().Fade() ;
      }else{
        break ;
      }
    }
  }
  
}

function Fade(){
  GetComponent.<Animation>().Play("BallFade") ;
}

function MoveToUp(){
	id *= -1 ;
  transform.position.y = 2+(2-transform.position.y) ;
}

function CheckFall(){
  GetComponent.<SpriteRenderer>().color.a = 1 ;
	var hits : RaycastHit2D[] = Physics2D.LinecastAll(transform.position, transform.position-transform.up*10, 1<<8) ;
  if(hits.length == 1){
  	id = Mathf.Abs(id%6)+24 ;
  }else{
  	id = hits[1].collider.GetComponent.<Ball>().id -6 ;
  }
  move = true ;
}

function OnTriggerEnter2D(other : Collider2D){
  
  for(var b:Ball in control.allBall){
    if(b.id == other.GetComponent.<BallSlot>().id){
      var temp : int = id ;
      id = b.id ;
      b.id = temp ;
      b.move = true ;
    }
  }
}
