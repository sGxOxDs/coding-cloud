using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Collision : MonoBehaviour
{
    [SerializeField] private LayerMask groundLayer;
    [SerializeField] private LayerMask wallLayer;
    [SerializeField] private float rayCastRadius;

    public bool onGround;
    public bool onWall;
    public bool onRightWall;
    public bool onLeftWall;

    void Update()
    {
        onGround = Physics2D.OverlapCircle(new Vector2(transform.position.x, transform.position.y - (transform.lossyScale.y / 2)), rayCastRadius, groundLayer);
        onWall = onRightWall || onLeftWall;
        onRightWall = Physics2D.OverlapCircle(new Vector2(transform.position.x + (transform.lossyScale.x / 2), transform.position.y), rayCastRadius, wallLayer);
        onLeftWall = Physics2D.OverlapCircle(new Vector2(transform.position.x - (transform.lossyScale.x / 2), transform.position.y), rayCastRadius, wallLayer);
    }

    private void OnDrawGizmos()
    {
        Gizmos.color = Color.green;
        Gizmos.DrawWireSphere(new Vector2(transform.position.x, transform.position.y - (transform.lossyScale.y / 2)), rayCastRadius);
        Gizmos.DrawWireSphere(new Vector2(transform.position.x - (transform.lossyScale.x / 2), transform.position.y), rayCastRadius);
        Gizmos.DrawWireSphere(new Vector2(transform.position.x + (transform.lossyScale.x / 2), transform.position.y), rayCastRadius);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (CompareTag("Player"))
        {

        }
    }
}
