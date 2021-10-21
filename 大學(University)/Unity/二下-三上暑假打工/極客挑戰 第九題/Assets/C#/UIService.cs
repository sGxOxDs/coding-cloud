using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIService : MonoBehaviour
{
    public static UIService op_port;
    private void Awake()
    {
        op_port = this;
    }

    public GameObject startmenu;
    public GameObject playingUI;
    public GameObject catchingUI;
    public GameObject gameovermenu;

    public float timer = 0f;

    public float power = 0f;
    public float poweraddsub = 10f;
    public bool addsubswitch = false;

    public float chance = 0f;

    public Motor[] motors_list;
    public float rotatespeed = 10f;

    public GameObject catcher;
    public float downspeed = 0.01f;
    public float gooriginspeed = 0.1f;
    public GameObject toyparent;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Power();
        Timer();
        Chance();
    }

    public void Timer()
    {
        if (playingUI.activeInHierarchy)
            timer += Time.deltaTime;
        else
            timer = 0;
        playingUI.transform.GetChild(0).GetComponent<Text>().text = "" + (20f - timer);
    }
    public void Power()
    {
        if(playingUI.activeInHierarchy)
        {
            if (power >= 95f)
            {
                power -= poweraddsub * Time.deltaTime;
                addsubswitch = true;
            }
            else if (power <= 5f)
            {
                power += poweraddsub * Time.deltaTime;
                addsubswitch = false;
            }
            else if (addsubswitch)
            {
                power -= poweraddsub * Time.deltaTime;
            }
            else
            {
                power += poweraddsub * Time.deltaTime;
            }
            playingUI.transform.GetChild(1).GetComponent<Scrollbar>().size = power / 100f;
        }
        
        catchingUI.transform.GetChild(0).GetComponent<Scrollbar>().size = power / 100f;
    }

    public void Chance()
    {
        int temp = 0;
        for (int i = 0; i < motors_list.Length; i++)
            if (motors_list[i].get_catch())
                temp++;
        chance = (power / 3f) * (float)temp;
        playingUI.transform.GetChild(2).GetComponent<Text>().text = "" + chance;
        catchingUI.transform.GetChild(1).GetComponent<Text>().text = "" + chance;
    }

    public void Catching()
    {
        playingUI.SetActive(false);
        catchingUI.SetActive(true);
        StartCoroutine(Down());
        
    }

    public void Catch(int op)
    {
        for (int i = 0; i < motors_list.Length; i++)
            motors_list[i].catching(op * rotatespeed);
    }

    IEnumerator Down()
    {
        Vector3 temp = catcher.transform.position;
        GameObject tmp = new GameObject();
        while (catcher.transform.position.y > 4)
        {
            catcher.transform.position = new Vector3(temp.x, catcher.transform.position.y - downspeed, temp.z);
            yield return new WaitForSeconds(0.01f) ;
        }
        yield return new WaitForSeconds(1f);
        Catch(1);
        yield return new WaitForSeconds(3f);
        if (chance >= Random.Range(0f, 100f)) 
        {
            CatchRay.op_port.GetLookAt().transform.parent = catcher.transform;
            CatchRay.op_port.GetLookAt().GetComponent<Rigidbody>().useGravity = false;
        }
        while (catcher.transform.position.y < 9)
        {
            catcher.transform.position = new Vector3(temp.x, catcher.transform.position.y + downspeed, temp.z);
            yield return new WaitForSeconds(0.01f);
        }
        tmp = catcher.transform.GetChild(0).GetChild(0).gameObject;
        for (int i = 0; i < 600; i++)
        {
            tmp.transform.localPosition = Vector3.Lerp(tmp.transform.localPosition, new Vector3(3f, 0, 3f), gooriginspeed);
            yield return new WaitForSeconds(0.01f);
            Debug.Log(i);
        }
        if (catcher.transform.childCount==3)
        {
            tmp = catcher.transform.GetChild(2).gameObject;
            tmp.transform.parent = toyparent.transform;
            tmp.GetComponent<Rigidbody>().useGravity = true;
        }
        yield return new WaitForSeconds(1f);
        Catch(-1);
        yield return new WaitForSeconds(5f);
        catchingUI.SetActive(false);
        gameovermenu.SetActive(true);
    }
    public void Restart_btn()
    {
        gameovermenu.SetActive(false);
        gameObject.GetComponent<ToStart>().enabled = true;
        startmenu.SetActive(true);
    }
}
