using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControl : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (GameObject.Find("robotSphere").GetComponent<Animator>().GetBool("Roll_Anim"))
        {
            gameObject.transform.position = Vector3.Lerp(gameObject.transform.position, gameObject.transform.Find("MoveAnchor").position, 0.05f);
        }
        else if (Input.GetKey("w"))
        {
            gameObject.transform.position = Vector3.Lerp(gameObject.transform.position, gameObject.transform.Find("MoveAnchor").position, 0.01f);
        }
    }
}
