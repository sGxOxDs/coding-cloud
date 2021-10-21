using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CatchRay : MonoBehaviour
{
    public static CatchRay op_port;
    private void Awake()
    {
        op_port = this;
    }
    public string interactivetag;

    private GameObject catcher;
    private GameObject go;//射線碰撞的物體

    private bool isdrage = false;

    void Start()
    {
        catcher = this.gameObject;
    }


    void Update()
    {
        if (isdrage == false)
        {
            //整體初始位置 
            Ray ray = new Ray();
            ray.origin = catcher.transform.position;
            
            ray.direction = -catcher.transform.up;
            //從攝像機發出到點選座標的射線
            RaycastHit hitInfo;

            if (Physics.Raycast(ray, out hitInfo))
            {
                //劃出射線，只有在scene檢視中才能看到
                Debug.DrawLine(ray.origin, hitInfo.point, Color.red);
                go = hitInfo.collider.gameObject;
            }
        }

        //拖拽物體不能為空
        if (go != null)
        {
            if (go.tag == interactivetag)
            {
                //isdrage = true;
                gameObject.transform.GetChild(3).gameObject.SetActive(true);
            }
            else
            {
                //結束後，清空物體
                go = null;
                isdrage = false;
                gameObject.transform.GetChild(3).gameObject.SetActive(false);
            }
        }

    }

    public GameObject GetLookAt()
    {
        if (go != null)
            return go;
        else
            return null;
    }
}

