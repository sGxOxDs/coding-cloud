using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Motor : MonoBehaviour
{
    private JointMotor motor;
    private bool have_catch = false;
    // Start is called before the first frame update
    void Start()
    {
        motor = gameObject.GetComponent<HingeJoint>().motor;
        have_catch = false;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void OnCollisionStay(Collision collision)
    {
        if (collision.gameObject == CatchRay.op_port.GetLookAt())
            have_catch = true;
        else
            have_catch = false;
    }

    public void catching(float op)
    {
        motor.targetVelocity = op;
        gameObject.GetComponent<HingeJoint>().motor = motor;
    }

    public bool get_catch()
    {
        return have_catch;
    }
}
