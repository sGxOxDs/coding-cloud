using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bead : MonoBehaviour
{
    [SerializeField] Beadservice beadservice;
    public string beadservicename;
    [SerializeField] GameObject crrentslot;
    // Start is called before the first frame update
    void Start()
    {
        crrentslot = this.gameObject.transform.parent.gameObject;
        beadservice = GameObject.Find(beadservicename).GetComponent<Beadservice>();
    }

    // Update is called once per frame
    void Update()
    {
        this.gameObject.transform.parent = crrentslot.transform;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (gameObject.transform.position.x != crrentslot.transform.position.x
            && gameObject.transform.position.y != crrentslot.transform.position.y) 
            beadservice.SwitchBeads(this, collision.gameObject.GetComponent<Bead>());
        //Debug.Log(this.gameObject+"Trigger");
    }

    public GameObject GetSlot()
    {
        return crrentslot;
    }

    public void SetSlot(GameObject newslot)
    {
        crrentslot = newslot;
    }

    public void PutIt()
    {
        this.gameObject.transform.position = crrentslot.transform.position + new Vector3(0, 0, -5);
    }
}
