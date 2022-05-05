using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class Look : MonoBehaviour
{
    public GameObject PlayerGO;
    private Vector3 offset;
    private Transform tPlayerGO;

    // Start is called before the first frame update
    void Start()
    {
        tPlayerGO = PlayerGO.transform;
        offset = transform.position - tPlayerGO.position;
    }

    // Update is called once per frame
    void Update()
    {
        if(Mouse.current.rightButton.isPressed)
        {
            transform.RotateAround(tPlayerGO.position, Vector3.up, 30 * Time.deltaTime);
            offset = transform.position - tPlayerGO.position;
        }
    }

    void LateUpdate()
    {
        var pos = tPlayerGO.position;
        transform.position = pos + offset;
    }
}
