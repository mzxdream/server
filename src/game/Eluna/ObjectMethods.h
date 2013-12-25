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

#ifndef OBJECTMETHODS_H
#define OBJECTMETHODS_H

namespace LuaObject
{
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int RemoveFlag(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint32 flag = luaL_checkunsigned(L, 2);

        obj->RemoveFlag(index, flag);
        return 0;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int SetFlag(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint32 flag = luaL_checkunsigned(L, 2);

        obj->SetFlag(index, flag);
        return 0;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int HasFlag(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint32 flag = luaL_checkunsigned(L, 2);

        sEluna.Push(L, obj->HasFlag(index, flag));
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetInt32Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        sEluna.Push(L, obj->GetInt32Value(index));
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetUInt32Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        sEluna.Push(L, obj->GetUInt32Value(index));
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetFloatValue(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        sEluna.Push(L, obj->GetFloatValue(index));
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetByteValue(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        sEluna.Push(L, obj->GetByteValue(index, offset));
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int GetUInt16Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        sEluna.Push(L, obj->GetUInt16Value(index, offset));
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int SetInt32Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        int32 value = luaL_checkinteger(L, 2);
        obj->SetInt32Value(index, value);
        return 0;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int SetUInt32Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);
        obj->SetUInt32Value(index, value);
        return 0;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int UpdateUInt32Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);
        obj->UpdateUInt32Value(index, value);
        return 0;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int SetFloatValue(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        float value = luaL_checknumber(L, 2);

        obj->SetFloatValue(index, value);
        return 0;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int SetByteValue(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint8 value = luaL_checkunsigned(L, 3);
        obj->SetByteValue(index, offset, value);
        return 0;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int SetUInt16Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint16 value = luaL_checkunsigned(L, 3);
        obj->SetUInt16Value(index, offset, value);
        return 0;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int SetInt16Value(lua_State* L, Object* obj)
    {
        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        int16 value = luaL_checkinteger(L, 3);
        obj->SetInt16Value(index, offset, value);
        return 0;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    static int ToCorpse(lua_State* L, Object* obj)
    {
        sEluna.Push(L, obj->ToCorpse());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    static int ToGameObject(lua_State* L, Object* obj)
    {
        sEluna.Push(L, obj->ToGameObject());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    static int ToUnit(lua_State* L, Object* obj)
    {
        sEluna.Push(L, obj->ToUnit());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    static int ToCreature(lua_State* L, Object* obj)
    {
        sEluna.Push(L, obj->ToCreature());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    static int ToPlayer(lua_State* L, Object* obj)
    {
        sEluna.Push(L, obj->ToPlayer());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    int SetScale(lua_State* L, Object* obj)
    {
        float size = luaL_checknumber(L, 1);

        obj->SetObjectScale(size);
        return 0;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    static int GetScale(lua_State* L, Object* obj)
    {
        sEluna.Push(L, obj->GetObjectScale());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    static int GetEntry(lua_State* L, Object* obj)
    {
        sEluna.Push(L, obj->GetEntry());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    static int GetGUID(lua_State* L, Object* obj)
    {
        sEluna.Push(L, obj->GetObjectGuid().GetRawValue());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    static int GetGUIDLow(lua_State* L, Object* obj)
    {
        sEluna.Push(L, obj->GetGUIDLow());
        return 1;
    }
    /**
     * @brief
     *
     * @param L
     * @param obj
     * @return int
     */
    static int IsInWorld(lua_State* L, Object* obj)
    {
        sEluna.Push(L, obj->IsInWorld());
        return 1;
    }
};
#endif