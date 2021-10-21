using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CatchService : MonoBehaviour
{
    public static CatchService op_port;
    private void Awake()
    {
        op_port = this;
    }
    public GameObject this_gameobject; 
    public GameObject frontanchor_gameobject;
    public GameObject behindanchor_gameobject;
    public GameObject rightanchor_gameobject;
    public GameObject leftanchor_gameobject;

    public Rigidbody this_rigidbody;
    public Motor[] motors_list;
    //public float movespeed = 10f;
    public float movespeed = 1f;
    public float rotatespeed = 10f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey("w"))
        {
            //this_rigidbody.AddForce(new Vector3(0, 0, -movespeed));
            this_gameobject.transform.position = Vector3.Lerp(this_gameobject.transform.position, frontanchor_gameobject.transform.position, movespeed * Time.deltaTime);
        }

        if (Input.GetKey("s"))
        {
            //this_rigidbody.AddForce(new Vector3(0, 0, movespeed));
            this_gameobject.transform.position = Vector3.Lerp(this_gameobject.transform.position, behindanchor_gameobject.transform.position, movespeed * Time.deltaTime * 0.75f);

        }

        if (Input.GetKey("d"))
        {
            //this_rigidbody.AddForce(new Vector3(-movespeed, 0, 0));
            this_gameobject.transform.position = Vector3.Lerp(this_gameobject.transform.position, rightanchor_gameobject.transform.position, movespeed * Time.deltaTime * 0.85f);

        }

        if (Input.GetKey("a"))
        {
            //this_rigidbody.AddForce(new Vector3(movespeed, 0, 0));
            this_gameobject.transform.position = Vector3.Lerp(this_gameobject.transform.position, leftanchor_gameobject.transform.position, movespeed * Time.deltaTime * 0.85f);

        }

        if (UIService.op_port.playingUI.activeInHierarchy)
        {
            catching(-1);
        }

        if (Input.GetKeyDown(KeyCode.Space)) 
        {
            UIService.op_port.Catching();
        }
        if (UIService.op_port.timer > 20) 
        {
            UIService.op_port.Catching();
        }
    }

    public void catching(int op)
    {
        for (int i = 0; i < motors_list.Length; i++) 
        {
            motors_list[i].catching(op * rotatespeed);
        }
        
    }
}
