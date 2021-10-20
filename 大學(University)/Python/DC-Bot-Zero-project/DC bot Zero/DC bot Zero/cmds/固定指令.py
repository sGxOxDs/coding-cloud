import discord
from discord.ext import commands
from core.classes import Cog_模組
import json, random, os

#訊息檔
with open("message.json",'r',encoding="ansi") as jfile:
    j訊息 = json.load(jfile)

class 固定指令(Cog_模組):

    #help 指令
    @commands.command()
    async def h(self, ctx):
        allmsg = ""
        for msg in j訊息["help"]:
            allmsg += (msg+"\n")
        await ctx.send(allmsg)

    #ping 指令
    @commands.command()
    async def p(self, ctx):
        await ctx.send(f"{round(self.bot.latency*1000)} (ms)")

    #圖片url 指令
    @commands.command()
    async def 圖(self, ctx):
        random_pic_url = random.choice(j訊息["pic_url"])
        await ctx.send(random_pic_url)

    #Cog的程式模塊完全重載
    @commands.Cog.listener()
    async def on_message(self, msg):
        if msg.author != self.bot.user: #防止機器人自己觸發自己
            if msg.content == "re a": #re a：快速reload全部模組
                for filename in os.listdir("./cmds"):
                    if filename.endswith(".py"):
                        try:
                            self.bot.reload_extension(f"cmds.{filename[:-3]}")
                            await msg.channel.send(f"重載 {filename[:-3]}")
                        except discord.DiscordException:
                            await msg.channel.send(f"重載 {filename[:-3]} 失敗")
                            await msg.channel.send(f"嘗試載入 {filename[:-3]}")
                            try:
                                self.bot.load_extension(f"cmds.{filename[:-3]}")
                                await msg.channel.send(f"載入 {filename[:-3]}")
                            except discord.DiscordException:
                                await msg.channel.send(f"載入 {filename[:-3]} 失敗")
                await msg.channel.send("重載完成 " + f"{msg.author.mention}")
            elif msg.content == "?": #?：指令表快捷
                allhmsg = ""
                for hmsg in j訊息["help"]:
                    allhmsg += (hmsg+"\n")
                await msg.channel.send(allhmsg)

def setup(bot):
    bot.add_cog(固定指令(bot))