# Unreal Engine 5 c++ demo of a weighted RNG item generator using data assets.

*** IMPORTANT: If you intend to download and open the project directly via git clone, please make sure you have git lfs installed. ***

## Video of the item generator in action:
### [YouTube video](https://www.youtube.com/watch?v=DjaYxrAhh-s)

## Files of interest:
### - [ItemAssetLoader.h](https://github.com/Alcalol/Item-Roll-Demo/blob/master/Source/ItemRollDemo/ItemAssetLoader.h) and [ItemAssetLoader.cpp](https://github.com/Alcalol/Item-Roll-Demo/blob/master/Source/ItemRollDemo/ItemAssetLoader.cpp)
### - [ItemRarityDataAsset.h](https://github.com/Alcalol/Item-Roll-Demo/blob/master/Source/ItemRollDemo/ItemRarityDataAsset.h) and [ItemRarityDataAsset.cpp](https://github.com/Alcalol/Item-Roll-Demo/blob/master/Source/ItemRollDemo/ItemRarityDataAsset.cpp)
### - [ItemActor.h](https://github.com/Alcalol/Item-Roll-Demo/blob/master/Source/ItemRollDemo/ItemActor.h) and [ItemActor.cpp](https://github.com/Alcalol/Item-Roll-Demo/blob/master/Source/ItemRollDemo/ItemActor.cpp)

## Description:
- A weighted RNG system that can select an item from a user selected list of rarities, accounting for each rarity's spawn chance.
- The item generator can also filter by item type.
- Individual item configurations are stored in Primary Data Assets which gets automatically loaded by the Asset Registry on launch.
- Item rarity configurations (Rarity colour and spawn chance) is also a data asset.
- Upon an item spawning, the Niagara effect circling the item is set to represent the rarity by colour.
- Widget displays on the wall also shows the info of the current item that is on each spawn platform.

Note: The platform the items spawn on is just a visual inside the actor class, so the item can be spawned anywhere on, in, or around any objects such as a table, a chest, or just on the ground with no object at all.

## Reasons for various decisions:
- Item status effects and the range at which they can roll at per item is implemented, however the code to actually generate the status effects was not, in order to limit the scope of the project.
- Some basic default meshes were used to represent different item types (Sphere = Ring, Cylinder = Weapons, Cone = Amulet etc...), as actually modelling individual item is also beyond the scope of this project.
- In the project, a single button controls all 5 spawn platforms for recording purposes, but any amount of spawn platforms can be bound do any amount of separate buttons.
- The spawn button is off center, which may trigger some people, but it would block the view of the center platform if it's dead center, I'm sorry!!
