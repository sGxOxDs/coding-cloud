using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove: MonoBehaviour
{
    public Transform startMarker;
    public Transform endMarker;
    public float speed = 1.0f;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.LookAt(endMarker);
        if(Input.GetKey(KeyCode.W))
        {
            transform.position = Vector3.Lerp(startMarker.position, endMarker.position, speed);
            Debug.Log("PlayerMove W");
        }
        //if (Input.GetKey(KeyCode.S))
        //{

        //}
        //if (Input.GetKey(KeyCode.A))
        //{

        //}
        //if (Input.GetKey(KeyCode.D))
        //{

        //}
    }
}
