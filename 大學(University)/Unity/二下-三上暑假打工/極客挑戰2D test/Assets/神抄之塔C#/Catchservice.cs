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

    private Camera cam;//�o�g�g�u���ṳ��
    private GameObject go;//�g�u�I��������
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
            //�����l��m 
            Ray ray = cam.ScreenPointToRay(Input.mousePosition);
            //�q�ṳ���o�X���I��y�Ъ��g�u
            //RaycastHit hitInfo;
            RaycastHit2D hitInfo = Physics2D.Raycast(ray.origin, ray.direction);
            Vector2 origin = Input.mousePosition;
            
            

            if (hitInfo.collider)
            {
                //���X�g�u�A�u���bscene�˵����~��ݨ�
                Debug.DrawLine(ray.origin, hitInfo.transform.position, Color.red);
                

                go = hitInfo.collider.gameObject;
                screenSpace = cam.WorldToScreenPoint(go.transform.position);
                offset = go.transform.position - cam.ScreenToWorldPoint(new Vector3(Input.mousePosition.x, Input.mousePosition.y, screenSpace.z));

            }
        }


        //������餣�ର��
        if (go != null)
        {
            //���� ���
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
                //������A�M�Ū���
                go = null;
                isdrage = false;
            }
            else
            {
                timer = 0f;
                //������A�M�Ū���
                go = null;
                isdrage = false;
            }
        }
    }
}
