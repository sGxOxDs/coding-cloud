using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bead : MonoBehaviour
{
    [SerializeField] Beadservice beadservice;
    [SerializeField] GameObject currentslot;
    public string bead_service;

    // Start is called before the first frame update
    void Start()
    {
        currentslot = this.gameObject.transform.parent.gameObject;
        beadservice = GameObject.Find(bead_service).GetComponent<Beadservice>();
    }

    
    // Update is called once per frame
    void Update()
    {
        this.gameObject.transform.parent = currentslot.transform;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (gameObject.transform.position.x != currentslot.transform.position.x
            && gameObject.transform.position.y != currentslot.transform.position.y)
            beadservice.SwitchBeads(this, collision.gameObject.GetComponent<Bead>());
    }

    public GameObject GetSlot()
    {
        return currentslot;
    }

    public void SetSlot(GameObject newslot)
    {
        currentslot = newslot;
    }
    public void PutIt()
    {
        this.gameObject.transform.position = currentslot.transform.position + new Vector3(0, 0, -5);
    }
}
