# SeaSparrow's Papyrus Extender

## Introduction


This is a very simple SKSE plugin that adds a few utility functions to Skyrim SE that I want to be able to access for a few future projects. Currently, it only adds 4 functions:
1. Enchantment GetEquippedAmmoEnchantment(Actor a_kActor)
2. Explosion GetAmmoExplosion(Ammo a_kAmmo)
3. Actor[] GetAllActorsInFaction(Faction a_kFaction)
4. Spell[] GetAllActorPlayableSpells(Actor a_kActor)

## Requirements, installation, and use
First, you need the appropriate [SKSE release](https://www.nexusmods.com/skyrimspecialedition/mods/30379) for your game's version. Install [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444) and then simply install the latest release with your mod manager. Unless otherwise specified, this supports all versions of Skyrim, but this might change in the future to only support 1.6.629+.

After installing the plugin, make sure that you enable the mod, and check that the script and script sources are properly installed. They should be, but it never hurts to have a sanity check!

In order to call a function, you will first need to import my script. This is done as such:

![Example Script](https://cdn.discordapp.com/attachments/625292279468523522/1106194554270523452/Screenshot_3.png)

Once you have done this, simply call the functions as they are needed. Most of them simply return game objects that you can then manipulate normally in your script.

## The functions
### GetAllActorPlayableSpells
The main reason why this exists. Given an actor parameter, this script returns all playable spells the actor knows. For example, using this function on the player at the start of the game will return a Spell array containing [Flames, Healing]. You can then manipulate them the same way you'd do regular papyrus objects.
### GetEquippedAmmoEnchantment
Returns the associated enchantment of the given actor's equipped ammo. Accounts for enchantments added through [Ammo Enchanting](https://www.nexusmods.com/skyrimspecialedition/mods/79764), or other means. Note that this requires the enchanted ammo to be equipped in order to work, not just be in their inventory.
### GetBaseAmmoEnchantment
Returns the associated enchantment of a given ammo. Note that this will not return anything if the base ammo record is not enchanted - but unless you are running Ammo Enchanting, this will never be the case. 
### GetAllActorsInFaction
Returns all actors within the given faction. Note that this is EXTREMELY slow. 

## Building
Want to build based on the source code? It can't be simpler. First, you need the VCPKG_ROOT environment variable. Download and extract VCPKG from the [official repository](https://github.com/microsoft/vcpkg). Then, create a new environment variable called VCPKG_ROOT, and make its variable value equal to the root installation of VCPKG (eg C:\vcpkg).	 Then, download and install [CMake](https://cmake.org/).

After that, you are done. Download the source code, open it with Visual Studio, give it a few minutes, choose a build option (debug/release) and hit build. If you are using MO2, consider setting up an environment variable called SKYRIM_MODS_FOLDER, pointing to the mods directory of your MO2 installation (eg C:\MO2\mods) for automatic deployment. 
