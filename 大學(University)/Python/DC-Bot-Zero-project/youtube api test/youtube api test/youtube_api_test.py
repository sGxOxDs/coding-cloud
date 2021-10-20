import requests
from pprint import pprint
from datetime import datetime
import json
#https://www.youtube.com/channel/UCFEd5V7VcxBPPcuMGpmvkQA/videos?view=2&live_view=503 之前直播
#https://www.youtube.com/channel/UCFEd5V7VcxBPPcuMGpmvkQA/videos?view=2&live_view=501 直播中
#https://www.youtube.com/channel/UCFEd5V7VcxBPPcuMGpmvkQA/videos?view=2&live_view=502 等待直播
YOUTUBE_API_KEY = "AIzaSyDrioA9DyAqDpf40K-D3cHYzWa0bSItxIE"

with open("tempvideo.json",'r',encoding="ansi") as jfile:
    temp_video = json.load(jfile)

def main():
    youtube_channel_id = "UCFEd5V7VcxBPPcuMGpmvkQA"

    youtube_spider = YoutubeSpider(YOUTUBE_API_KEY)
    uploads_id = youtube_spider.get_channel_uploads_id(youtube_channel_id)
    print(uploads_id)

    video_ids = youtube_spider.get_playlist(uploads_id, max_results=1)
    print(video_ids)

    for video_id in video_ids:
        print("----------------------")
        video_info = youtube_spider.get_video(video_id)
        print(video_info)

    if video_info["id"] == temp_video["id"]:
        print("=O=")
    else:
        print("=X=")

    with open("tempvideo.json","w") as f:
        json.dump(video_info, f) 
    

class YoutubeSpider():
    def __init__(self, api_key):
        self.base_url = "https://www.googleapis.com/youtube/v3/"
        self.api_key = api_key

    def get_html_to_json(self, path):
        """組合 URL 後 GET 網頁並轉換成 JSON"""
        api_url = f"{self.base_url}{path}&key={self.api_key}"
        r = requests.get(api_url)
        if r.status_code == requests.codes.ok:
            data = r.json()
        else:
            data = None
        return data

    def get_channel_uploads_id(self, channel_id, part='contentDetails'):
        """取得頻道上傳影片清單的ID"""
        path = f'channels?part={part}&id={channel_id}'
        data = self.get_html_to_json(path)
        try:
            uploads_id = data['items'][0]['contentDetails']['relatedPlaylists']['uploads']
        except KeyError:
            uploads_id = None
        return uploads_id

    def get_playlist(self, playlist_id, part='contentDetails', max_results=10):
        """取得影片清單ID中的影片"""
        path = f'playlistItems?part={part}&playlistId={playlist_id}&maxResults={max_results}'
        data = self.get_html_to_json(path)
        if not data:
            return []

        video_ids = []
        for data_item in data['items']:
            video_ids.append(data_item['contentDetails']['videoId'])
        return video_ids

    def get_video(self, video_id, part='snippet,statistics'):
        """取得影片資訊"""
        # jyordOSr4cI
        # part = 'contentDetails,id,liveStreamingDetails,localizations,player,recordingDetails,snippet,statistics,status,topicDetails'
        path = f'videos?part={part}&id={video_id}'
        data = self.get_html_to_json(path)
        if not data:
            return {}
        # 以下整理並提取需要的資料
        data_item = data['items'][0]

        try:
            # 2019-09-29T04:17:05Z
            time_ = datetime.strptime(data_item['snippet']['publishedAt'], '%Y-%m-%d %H:%M:%S')
        except ValueError:
            # 日期格式錯誤
            time_ = None

        url_ = f"https://www.youtube.com/watch?v={data_item['id']}"

        info = {
            'id': data_item['id'],
            'channelTitle': data_item['snippet']['channelTitle'],
            'publishedAt': data_item['snippet']['publishedAt'],
            'video_url': url_,
            'title': data_item['snippet']['title']
            #'description': data_item['snippet']['description'],
            #'likeCount': data_item['statistics']['likeCount'],
            #'dislikeCount': data_item['statistics']['dislikeCount'],
            #'commentCount': data_item['statistics']['commentCount'],
            #'viewCount': data_item['statistics']['viewCount']
        }
        return info

    def get_live(self, video_id, part='snippet,statistics'):
        """取得影片資訊"""
        # jyordOSr4cI
        # part = 'contentDetails,id,liveStreamingDetails,localizations,player,recordingDetails,snippet,statistics,status,topicDetails'
        path = f'videos?part={part}&id={video_id}'
        data = self.get_html_to_json(path)
        if not data:
            return {}
        # 以下整理並提取需要的資料
        data_item = data['items'][0]

        try:
            # 2019-09-29T04:17:05Z
            time_ = datetime.strptime(data_item['snippet']['publishedAt'], '%Y-%m-%d %H:%M:%S')
        except ValueError:
            # 日期格式錯誤
            time_ = None

        url_ = f"https://www.youtube.com/watch?v={data_item['id']}"

        info = {
            'id': data_item['id'],
            'channelTitle': data_item['snippet']['channelTitle'],
            'publishedAt': data_item['snippet']['publishedAt'],
            'video_url': url_,
            'title': data_item['snippet']['title']
            #'description': data_item['snippet']['description'],
            #'likeCount': data_item['statistics']['likeCount'],
            #'dislikeCount': data_item['statistics']['dislikeCount'],
            #'commentCount': data_item['statistics']['commentCount'],
            #'viewCount': data_item['statistics']['viewCount']
        }
        return info

if __name__ == "__main__":
    main()

