# BattleTank_UECourse
Ben Tristem's Unreal Engine Development Kit Course. Open World tank fighting game

## Main reason to make this
This project is mainly for learning how to program in-depth C++ and to use UDK to it's full potential. 
I want to be able to make a game independently without help and make a name for myself in the gaming industry.

## Why use GitHub
I am using GitHub for this project to both backup my project and to create an online resume for myself.

## Redistribution
Go ahead and use my code for whatever you please, if you pull from it, I wouldn't mind a simple mention on a readme or credits :) but it isn't needed. 

# Game Design Document (GDD)

## Concept
core concept is a head to head tank fighting game where you have to destroy a tank before it destroys you!
Start in a tank and aim at other tanks while using cover, moving away, or straight up dominating the other tank.

## Rules
* infinite ammo
* Lose condition - HP drops to Zero and tank explodes
* Mountains surround map as boundaries
* You can only shoot where turret slowly moves to.
* Must fire and hit tank to deal damage
* Win Condition - Enemy Tank HP reaches zero and explodes

## Requirements
* Tank Assets need to be built with shapes or other means Ben Tristem provides.
* C++ and Blueprint to encode behavior of Tank and controls
* Sound Effects - Tank Engine, Explosions, Hit marker lel.
* Music - Background tension music, Win music, Lose music
* Landscaping tools for map
* UI elements for HP, Reload Speed, Crosshairs(both on target and off)
* Destructable Environment
