using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.InputSystem;

public class Move : MonoBehaviour
{
    private NavMeshAgent agent;
    private Vector3 target;
    private Animator animator;

    void Start()
    {
        agent = GetComponent<NavMeshAgent>();
        target = transform.position;
        animator = GetComponentInChildren<Animator>();
    }
    void Update()
    {
        Ray ray = Camera.main.ScreenPointToRay(Mouse.current.position.ReadValue());
        RaycastHit hit;
        if (Mouse.current.leftButton.wasPressedThisFrame
            && Physics.Raycast(ray, out hit)
            && hit.transform.gameObject.CompareTag("floor") )
        {
            target = hit.point;
        }
        agent.SetDestination(target);
        animator.SetFloat("speed", agent.velocity.sqrMagnitude);
    }
}
