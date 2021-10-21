using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.IO;
using System.Text;

public class UIservice : MonoBehaviour
{
    public static UIservice op_port;
    private void Awake()
    {
        op_port = this;
    }
    public GameObject startmenu;
    public GameObject playingUI;
    public GameObject FallingUI;
    public GameObject gameovermenu;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        Timer();
        if (level == 3)
            GameOver();
    }
    float time_start;
    float time_end;
    public void StartGame_btn()
    {
        startmenu.SetActive(false);

        FallingUI.SetActive(true);
        Beadservice.op_port.FillBeads();
        FallingUI.SetActive(false);
        level = 1;
        playingUI.SetActive(true);
        time_start = Time.time;
    }

    public void Timer()
    {
        playingUI.transform.GetChild(3).GetComponent<Text>().text = "" + (15f - Catchservice.op_port.timer);
        playingUI.transform.GetChild(4).GetComponent<Scrollbar>().size = (15f - Catchservice.op_port.timer) / 15f;
    }

    [SerializeField] int level = 0;
    public void LevelUp(int link)
    {
        if (level == 1 && link >= 3)
            level = 2;
        else if (level == 2 && link >= 8)
            level = 3;
        else if (level == 3 && link >= 13)
            level = 4;
        else if (level == 4 && link >= 18)
            level = 5;
        else if (level == 5 && link >= 23)
            level = 6;
    }

    public void GameOver()
    {
        level = 0;
        time_end = Time.time;
        Save(time_end - time_start);
        playingUI.SetActive(false);
        gameovermenu.SetActive(true);
        gameovermenu.transform.GetChild(1).GetComponent<Text>().text=""+ (time_end - time_start);
        
    }
    public void ReStart_btn()
    {
        gameovermenu.SetActive(false);
        StartGame_btn();
    }
    [SerializeField] TextAsset ranktxt;
    public void Save(float score)
    {
        List<string> rank = new List<string>();

        string[] temp = File.ReadAllLines("Assets/" + ranktxt.name + ".txt");

        for (int i = 0; i < temp.Length; i++)
            rank.Add(temp[i]);

        for (int i = 0; i < rank.Count; i++)
            if (float.Parse(rank[i]) > score)
            {
                rank.Insert(i, score.ToString());
                break;
            }

        if (rank.Count == 0)
            rank.Add(score.ToString());

        gameovermenu.transform.GetChild(2).GetComponent<Text>().text = "";
        temp = new string[10];
        for (int i = 0; i < rank.Count && i < 10; i++)
        {
            temp[i] = rank[i];
            if (rank[i] != "999.999")
                gameovermenu.transform.GetChild(2).GetComponent<Text>().text += rank[i] + "\n";
            else
                gameovermenu.transform.GetChild(2).GetComponent<Text>().text += "null\n";
        }
        for (int i = rank.Count; i < 10; i++)
            temp[i] = "";
        File.WriteAllLines("Assets/" + ranktxt.name + ".txt", temp);

    }
}