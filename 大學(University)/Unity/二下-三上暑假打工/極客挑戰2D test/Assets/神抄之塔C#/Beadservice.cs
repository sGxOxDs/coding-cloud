using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Beadservice : MonoBehaviour
{
    public GameObject all_slot;
    [SerializeField] GameObject[] slot_list;
    public GameObject beadbase;
    public Sprite[] beadsimg;

    public static Beadservice op_port;
    public bool fillswitch = false;
    public int linkcount = 0;

    private void Awake()
    {
        op_port = this;
    }

    // Start is called before the first frame update
    void Start()
    {
        int childcount = all_slot.transform.childCount;
        
        for (int i = 0; i < childcount; i++)
            slot_list[i] = all_slot.transform.GetChild(i).gameObject;

    }

    // Update is called once per frame
    void Update()
    {
        if (fillswitch)
            Falling();
    }

    public void SwitchBeads(Bead left,Bead right)
    {
        GameObject temp = left.GetSlot();
        left.SetSlot(right.GetSlot());
        right.SetSlot(temp);
        right.PutIt();
    }

    public void FallBeads()
    {
        for (int i = 0; i < 6; i++)
        {
            bool empty_slot = false;
            for (int j = 4; j > 0; j--)
            {
                if (slot_list[i + j * 6].transform.childCount == 0
                    && slot_list[i + (j - 1) * 6].transform.childCount == 1)
                {
                    Bead temp = slot_list[i + (j - 1) * 6].transform.GetChild(0).gameObject.GetComponent<Bead>();
                    temp.SetSlot(slot_list[i + j * 6]);
                    temp.PutIt();
                    empty_slot = true;
                }
                else if (slot_list[i + j * 6].transform.childCount == 1
                    && slot_list[i + (j - 1) * 6].transform.childCount == 1
                    && empty_slot)
                {
                    Bead temp = slot_list[i + (j - 1) * 6].transform.GetChild(0).gameObject.GetComponent<Bead>();
                    temp.SetSlot(slot_list[i + j * 6]);
                    temp.PutIt();
                    empty_slot = true;
                }

            }
        }
    }
    
    public void CreateBeads()
    {
        for(int i=0;i<6;i++)
        {
            if(slot_list[i].transform.childCount == 0)
            {
                GameObject temp = Instantiate(beadbase, slot_list[i].transform);
                int rand = Random.Range(0, 5);
                temp.GetComponent<SpriteRenderer>().sprite = beadsimg[rand];
                //temp.GetComponent<Bead>().PutIt();
            }
        }
    }

    public int LinkBeads()
    {
        //Dictionary<int, GameObject> destory_list = new Dictionary<int, GameObject>();
        HashSet<GameObject> destory_list = new HashSet<GameObject>();
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 5; j++) 
            {
                if (slot_list[i + j * 6].transform.childCount == 0) continue;
                Sprite temp = slot_list[i + j * 6].transform.GetChild(0).GetComponent<SpriteRenderer>().sprite;
                if (i - 1 >= 0 && i + 1 < 6)
                {
                    if (slot_list[(i - 1) + j * 6].transform.childCount == 0
                        || slot_list[(i + 1) + j * 6].transform.childCount == 0) continue;

                    bool found = true;
                    for (int p=0;p<3;p++)
                        if(slot_list[(i - 1 + p) + j * 6].transform.GetChild(0).GetComponent<SpriteRenderer>().sprite!=temp)
                            found = false;

                    if(found)
                    {
                        for (int p = 0; p < 3; p++)
                            destory_list.Add(slot_list[(i - 1 + p) + j * 6].transform.GetChild(0).gameObject);
                    }
                }
                if (j - 1 >= 0 && j + 1 < 5)
                {
                    if (slot_list[i + (j - 1) * 6].transform.childCount == 0
                        || slot_list[i + (j + 1) * 6].transform.childCount == 0) continue;

                    bool found = true;
                    for (int p = 0; p < 3; p++)
                        if (slot_list[i + (j - 1 + p) * 6].transform.GetChild(0).GetComponent<SpriteRenderer>().sprite != temp) 
                            found = false;

                    if (found)
                    {
                        for (int p = 0; p < 3; p++)
                            destory_list.Add(slot_list[i + (j - 1 + p) * 6].transform.GetChild(0).gameObject);
                    }
                }
            }
        }

        if (destory_list.Count == 0) return 0;

        for (int i = 0; i < 30; i++)
            if (destory_list.Contains(slot_list[i].transform.GetChild(0).gameObject)) 
                Destroy(slot_list[i].transform.GetChild(0).gameObject);

        Debug.Log("Destroy:" + destory_list.Count);
        return destory_list.Count;
    }

    public void FillBeads()
    {
        StartCoroutine(Fallend());
    }

    public void Falling()
    {
        if (!CheckBeadsFill())
        {
            FallBeads();
            CreateBeads();
            return;
        }
        int temp = LinkBeads();
        if (temp == 0)
        {
            Debug.Log("fill ED");
            fillswitch = false;
        }
        else
        {
            Debug.Log("filling");
            linkcount += temp;
        }
        
    }

    public bool CheckBeadsFill()
    {
        for(int i=0;i< all_slot.transform.childCount; i++)
            if (slot_list[i].transform.childCount == 0)
                return false;
        return true;
    }

    public IEnumerator Fallend()
    {
        fillswitch = true;
        linkcount = 0;
        yield return new WaitUntil(() => !fillswitch && CheckBeadsFill());
        Debug.Log("linkcount:" + linkcount);
        UIservice.op_port.LevelUp(linkcount);
    }

    public void ClearBeads()
    {
        for (int i = 0; i < 30; i++)
            Destroy(slot_list[i].transform.GetChild(0).gameObject);
    }
}
