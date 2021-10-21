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
    private GameObject go;//�g�u�I��������

    private bool isdrage = false;

    void Start()
    {
        catcher = this.gameObject;
    }


    void Update()
    {
        if (isdrage == false)
        {
            //�����l��m 
            Ray ray = new Ray();
            ray.origin = catcher.transform.position;
            
            ray.direction = -catcher.transform.up;
            //�q�ṳ���o�X���I��y�Ъ��g�u
            RaycastHit hitInfo;

            if (Physics.Raycast(ray, out hitInfo))
            {
                //���X�g�u�A�u���bscene�˵����~��ݨ�
                Debug.DrawLine(ray.origin, hitInfo.point, Color.red);
                go = hitInfo.collider.gameObject;
            }
        }

        //������餣�ର��
        if (go != null)
        {
            if (go.tag == interactivetag)
            {
                //isdrage = true;
                gameObject.transform.GetChild(3).gameObject.SetActive(true);
            }
            else
            {
                //������A�M�Ū���
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

