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

    Camera cam;
    GameObject go;
    Vector3 screenspace;
    Vector3 offset;
    bool isdrage = false;
    public float timer = 0f;

    // Start is called before the first frame update
    void Start()
    {
        cam = Camera.main;
    }

    // Update is called once per frame
    void Update()
    {
        if (isdrage == false)
        {
            Ray ray = cam.ScreenPointToRay(Input.mousePosition);
            RaycastHit2D hit2D = Physics2D.Raycast(ray.origin, ray.direction);
            Vector2 origin = Input.mousePosition;

            if (hit2D.collider)
            {
                go = hit2D.collider.gameObject;
                screenspace = cam.WorldToScreenPoint(go.transform.position);
                offset = go.transform.position - cam.ScreenToWorldPoint(new Vector3(Input.mousePosition.x, Input.mousePosition.y, screenspace.z));
            }
        }

        if (go != null)
        {

            if (Input.GetMouseButton(0) && go.tag == interactivetag && timer <= 15)
            {
                Vector3 currentscreenspace = cam.ScreenToWorldPoint(new Vector3(Input.mousePosition.x, Input.mousePosition.y, screenspace.z));
                Vector3 currentposition = currentscreenspace + offset;

                go.transform.position = currentposition;
                isdrage = true;
                timer += Time.deltaTime;
            }
            else if (Input.GetMouseButtonUp(0) || timer > 15)  
            {
                if(go.gameObject.TryGetComponent(out Bead bead))
                {
                    bead.PutIt();
                    Beadservice.op_port.FillBeads();
                }
                timer = 0f;
                go = null;
                isdrage = false;
            }
            else
            {
                timer = 0f;
                go = null;
                isdrage = false;
            }
        }
    }
}
