import discord
from discord.ext import commands
import json, random, os

#設定檔
with open("setting.json",'r',encoding="ansi") as jfile:
    j設定 = json.load(jfile)

#訊息檔
with open("message.json",'r',encoding="ansi") as jfile:
    j訊息 = json.load(jfile)

intents = discord.Intents.default()
intents.members = True

bot = commands.Bot(command_prefix="z.. ",intents = intents)

#運作指示
@bot.event
async def on_ready():
    print(">>機器人運作中<<")

#Cog的程式模塊載入
@bot.command()
async def load(ctx, 模組):
    try:
        bot.load_extension(f"cmds.{模組}")
        await ctx.send(f"載入 {模組}")
    except discord.DiscordException:
        await ctx.send(f"載入 {模組} 失敗")

#Cog的程式模塊卸載
@bot.command()
async def unload(ctx, 模組):
    try:
        bot.unload_extension(f"cmds.{模組}")
        await ctx.send(f"卸載 {模組}")
    except discord.DiscordException:
        await ctx.send(f"卸載 {模組} 失敗")

#Cog的程式模塊重載
@bot.command()
async def reload(ctx, 模組):
    try:
        bot.reload_extension(f"cmds.{模組}")
        await ctx.send(f"重載 {模組}")
    except discord.DiscordException:
        await ctx.send(f"重載 {模組} 失敗")

#Cog的程式模塊
for filename in os.listdir("./cmds"):
    if filename.endswith(".py"):
        bot.load_extension(f"cmds.{filename[:-3]}")

if __name__ == "__main__":
    bot.run(j設定["token"]) #bot.run( "token" )