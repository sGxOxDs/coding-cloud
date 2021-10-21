using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SControl : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKey ("d"))
        {
            gameObject.transform.position += new Vector3(0.05f,0,0);
        }
        if (Input.GetKey("a"))
        {
            gameObject.transform.position += new Vector3(-0.05f, 0, 0);
        }
    }
}
