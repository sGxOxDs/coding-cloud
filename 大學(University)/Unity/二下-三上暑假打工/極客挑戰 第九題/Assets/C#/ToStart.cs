using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ToStart : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            UIService.op_port.startmenu.SetActive(false);
            UIService.op_port.playingUI.SetActive(true);
            this.enabled = false;
        }
    }
}
