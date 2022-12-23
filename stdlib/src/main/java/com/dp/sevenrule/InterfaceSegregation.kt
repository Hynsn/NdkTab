package com.dp.sevenrule

interface BadCharacterSkill {
    fun basicAttach()
    fun magicAttach()
    fun recover()
}

class Monster : BadCharacterSkill {
    override fun basicAttach() {
        println("Monster basicAttach")
    }

    override fun magicAttach() {
        // 空实现
    }

    override fun recover() {
        // 空实现
    }
}

class MonsterBoss : BadCharacterSkill {
    override fun basicAttach() {
        println("MonsterBoss basicAttach")
    }

    override fun magicAttach() {
        println("MonsterBoss magicAttach")
    }

    override fun recover() {
        println("MonsterBoss recover")
    }
}

interface BasicBadCharacterSkill {
    fun basicAttach()
}

interface AdvanceBadCharacterSkill {
    fun magicAttach()
    fun recover()
}

class Monster1 : BasicBadCharacterSkill {
    override fun basicAttach() {
        println("Monster1 basicAttach")
    }
}

class MonsterBoss1 : BasicBadCharacterSkill, AdvanceBadCharacterSkill {
    override fun basicAttach() {
        println("MonsterBoss1 basicAttach")
    }

    override fun magicAttach() {
        println("MonsterBoss1 magicAttach")
    }

    override fun recover() {
        println("MonsterBoss1 recover")
    }
}
