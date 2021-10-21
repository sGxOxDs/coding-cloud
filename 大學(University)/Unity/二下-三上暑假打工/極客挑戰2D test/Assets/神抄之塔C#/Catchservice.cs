using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Catchservice : MonoBehaviour
{
    public static Catchservice op_port;
    private void Awake()
    {
        op_port = this;
    }

    public string interactivetag;

    private Camera cam;//發射射線的攝像機
    private GameObject go;//射線碰撞的物體
    private Vector3 screenSpace;
    private Vector3 offset;

    private bool isdrage = false;
    public float timer = 0f;

    void Start()
    {
        cam = Camera.main;
    }


    void Update()
    {
        if (isdrage == false)
        {
            //整體初始位置 
            Ray ray = cam.ScreenPointToRay(Input.mousePosition);
            //從攝像機發出到點選座標的射線
            //RaycastHit hitInfo;
            RaycastHit2D hitInfo = Physics2D.Raycast(ray.origin, ray.direction);
            Vector2 origin = Input.mousePosition;
            
            

            if (hitInfo.collider)
            {
                //劃出射線，只有在scene檢視中才能看到
                Debug.DrawLine(ray.origin, hitInfo.transform.position, Color.red);
                

                go = hitInfo.collider.gameObject;
                screenSpace = cam.WorldToScreenPoint(go.transform.position);
                offset = go.transform.position - cam.ScreenToWorldPoint(new Vector3(Input.mousePosition.x, Input.mousePosition.y, screenSpace.z));

            }
        }


        //拖拽物體不能為空
        if (go != null)
        {
            //長按 拖拽
            if (Input.GetMouseButton(0) && go.tag == interactivetag && timer <= 15) 
            {
                Vector3 currentScreenSpace = cam.ScreenToWorldPoint(new Vector3(Input.mousePosition.x, Input.mousePosition.y, screenSpace.z));
                Vector3 currentPosition = currentScreenSpace + offset;

                go.transform.position = currentPosition;
                isdrage = true;

                timer += Time.deltaTime;
                //Debug.Log((int)timer);
            }
            else if(Input.GetMouseButtonUp(0))
            {
                if (go.gameObject.TryGetComponent(out Bead bead))
                {
                    bead.PutIt();
                    Beadservice.op_port.FillBeads();
                }
                timer = 0f;
                //結束後，清空物體
                go = null;
                isdrage = false;
            }
            else
            {
                timer = 0f;
                //結束後，清空物體
                go = null;
                isdrage = false;
            }
        }
    }
}
