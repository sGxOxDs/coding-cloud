using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public GameObject[] objects = new GameObject[4];
    public float speed = 2f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKey(KeyCode.W))
        {
            Debug.Log("w press");
            transform.position = Vector3.Lerp(transform.position, objects[0].transform.position, speed * Time.deltaTime);
        }
        if(Input.GetKey(KeyCode.A))
        {
            Debug.Log("a press");
            transform.position = Vector3.Lerp(transform.position, objects[1].transform.position, speed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.S))
        {
            Debug.Log("s press");
            transform.position = Vector3.Lerp(transform.position, objects[2].transform.position, speed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.D))
        {
            Debug.Log("d press");
            transform.position = Vector3.Lerp(transform.position, objects[3].transform.position, speed * Time.deltaTime);
        }
    }

}
