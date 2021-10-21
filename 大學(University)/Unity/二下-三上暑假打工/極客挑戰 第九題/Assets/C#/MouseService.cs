using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MouseService : MonoBehaviour
{

    public float sensitivityX = 10f;
    public float sensitivityY = 10f;
    public float movespreed = 1f;
    private Camera cam;

    void Start()
    {
        cam = Camera.main;
    }


    void Update()
    {
        if (Input.GetMouseButton(0))
        {
            float rotationX = Input.GetAxis("Mouse X") * sensitivityX;
            float rotationY = Input.GetAxis("Mouse Y") * sensitivityY;
            cam.transform.Rotate(-rotationY, rotationX, 0);
        }
        if (Input.GetMouseButton(1))
        {
            float moveX = Input.GetAxis("Mouse X") * movespreed;
            float moveY = Input.GetAxis("Mouse Y") * movespreed;
            cam.transform.position=new Vector3(cam.transform.position.x+moveX, cam.transform.position.y, cam.transform.position.z+moveY);
        }

    }
}
