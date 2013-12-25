/**
 * mangos-zero is a full featured server for World of Warcraft in its vanilla
 * version, supporting clients for patch 1.12.x.
 *
 * Eluna provides an alternative Lua based scripting which allows your to
 * easily customize game content without the need for compilers or any
 * other development tools.
 *
 * Copyright (C) 2010-2013  Eluna Lua Engine <http://emudevs.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * World of Warcraft, and all World of Warcraft or Warcraft art, images,
 * and lore are copyrighted by Blizzard Entertainment, Inc.
 */

#ifndef WORLDOBJECTMETHODS_H
#define WORLDOBJECTMETHODS_H

namespace LuaWorldObject
{
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetName(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetName());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetMap(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetMap());
        return 1;
    }
    /*int GetPhaseMask(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetPhaseMask());
        return 1;
    }*/
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetInstanceId(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetInstanceId());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetAreaId(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetAreaId());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetZoneId(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetZoneId());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetMapId(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetMapId());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetX(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetPositionX());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetY(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetPositionY());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetZ(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetPositionZ());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetO(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetOrientation());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetLocation(lua_State* L, WorldObject* obj)
    {
        sEluna.Push(L, obj->GetPositionX());
        sEluna.Push(L, obj->GetPositionY());
        sEluna.Push(L, obj->GetPositionZ());
        sEluna.Push(L, obj->GetOrientation());
        return 4;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetNearestPlayer(lua_State* L, WorldObject* obj)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);

        Unit* target = NULL;
        Eluna::WorldObjectInRangeCheck checker(true, obj, range, TYPEID_PLAYER);
        MaNGOS::UnitLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(target, checker);
        Cell::VisitWorldObjects(obj, searcher, range);

        sEluna.Push(L, target);
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetNearestGameObject(lua_State* L, WorldObject* obj)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);
        uint32 entry = luaL_optunsigned(L, 2, 0);

        GameObject* target = NULL;
        Eluna::WorldObjectInRangeCheck checker(true, obj, range, TYPEID_GAMEOBJECT, entry);
        MaNGOS::GameObjectLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(target, checker);
        Cell::VisitGridObjects(obj, searcher, range);

        sEluna.Push(L, target);
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetNearestCreature(lua_State* L, WorldObject* obj)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);
        uint32 entry = luaL_optunsigned(L, 2, 0);

        Creature* target = NULL;
        Eluna::WorldObjectInRangeCheck checker(true, obj, range, TYPEID_UNIT, entry);
        MaNGOS::CreatureLastSearcher<Eluna::WorldObjectInRangeCheck> searcher(target, checker);
        Cell::VisitGridObjects(obj, searcher, range);

        sEluna.Push(L, target);
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetPlayersInRange(lua_State* L, WorldObject* obj)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);

        std::list<Player*> list;
        Eluna::WorldObjectInRangeCheck checker(false, obj, range, TYPEID_PLAYER);
        MaNGOS::PlayerListSearcher<Eluna::WorldObjectInRangeCheck> searcher(list, checker);
        Cell::VisitWorldObjects(obj, searcher, range);

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (std::list<Player*>::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            sEluna.Push(L, ++i);
            sEluna.Push(L, *it);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetCreaturesInRange(lua_State* L, WorldObject* obj)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);
        uint32 entry = luaL_optunsigned(L, 2, 0);

        std::list<Creature*> list;
        Eluna::WorldObjectInRangeCheck checker(false, obj, range, TYPEID_UNIT);
        MaNGOS::CreatureListSearcher<Eluna::WorldObjectInRangeCheck> searcher(list, checker);
        Cell::VisitGridObjects(obj, searcher, range);

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (std::list<Creature*>::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            sEluna.Push(L, ++i);
            sEluna.Push(L, *it);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetGameObjectsInRange(lua_State* L, WorldObject* obj)
    {
        float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);
        uint32 entry = luaL_optunsigned(L, 2, 0);

        std::list<GameObject*> list;
        Eluna::WorldObjectInRangeCheck checker(false, obj, range, TYPEID_GAMEOBJECT);
        MaNGOS::GameObjectListSearcher<Eluna::WorldObjectInRangeCheck> searcher(list, checker);
        Cell::VisitGridObjects(obj, searcher, range);

        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (std::list<GameObject*>::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            sEluna.Push(L, ++i);
            sEluna.Push(L, *it);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetWorldObject(lua_State* L, WorldObject* obj)
    {
        ObjectGuid guid = ObjectGuid(sEluna.CHECK_ULONG(L, 1));

        switch (guid.GetHigh())
        {
            case HIGHGUID_PLAYER:        sEluna.Push(L, obj->GetMap()->GetPlayer(guid)); break;
            case HIGHGUID_TRANSPORT:
            case HIGHGUID_MO_TRANSPORT:
            case HIGHGUID_GAMEOBJECT:    sEluna.Push(L, obj->GetMap()->GetGameObject(guid)); break;
            case HIGHGUID_UNIT:
            case HIGHGUID_PET:           sEluna.Push(L, obj->GetMap()->GetAnyTypeCreature(guid)); break;
            default:                     return 0;
        }
        return 1;
    }
};
#endif