import discord
from discord.ext import commands
from core.classes import Cog_模組
import json, random

#訊息檔
with open("message.json",'r',encoding="ansi") as jfile:
    j訊息 = json.load(jfile)

class 自動回復(Cog_模組):

    @commands.Cog.listener()
    async def on_message(self, msg):
        if msg.author != self.bot.user: #防止機器人自己觸發自己
            if msg.content == "join": #join：SV歡迎訊息
                random_join = random.choice(j訊息["join_message"])
                await msg.channel.send(f"{msg.author.mention} " + random_join)
            elif msg.content == "leave": #leave：SV離開訊息
                random_leave = random.choice(j訊息["leave_message"])
                await msg.channel.send(f"{msg.author.mention} " + random_leave)
            elif msg.content == "pic": #pic：圖庫挑一張
                random_pic = random.choice(j訊息["pic_url"])
                await msg.channel.send(random_pic)
            elif msg.content == "TK888": #TK888：對應訊息
                await msg.channel.send(j訊息["TK888"])
            elif msg.content == "LOL D5":
                hero_list = ""
                for i in range(0,5):
                    hero = random.choice(j訊息["LOL_Heros"])
                    hero_list += (hero+"\n")
                await msg.channel.send(hero_list)
            elif msg.content == "LOL D3":
                hero_list = ""
                for i in range(0,3):
                    hero = random.choice(j訊息["LOL_Heros"])
                    hero_list += (hero+"\n")
                await msg.channel.send(hero_list)

def setup(bot):
    bot.add_cog(自動回復(bot))