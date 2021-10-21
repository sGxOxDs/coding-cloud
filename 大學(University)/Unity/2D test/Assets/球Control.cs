using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class 球Control : MonoBehaviour
{
    Rigidbody2D ballRigidbody2D;
    CircleCollider2D ballCircleCollider2D;


    // Start is called before the first frame update
    void Start()
    {
        ballRigidbody2D = GetComponent<Rigidbody2D>();
        ballCircleCollider2D = GetComponent<CircleCollider2D>();
    }

    // Update is called once per frame
    void Update()
    {
        gameObject.transform.position += new Vector3(0, -0.025f, 0);
    }
}
