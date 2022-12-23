package com.dp.sevenrule

class BWM {
    fun rentBWM(model: String) {
        println("BWM $model")
    }
}

interface CarManufactory {
    fun rent(model: String)
}

class BWM1 : CarManufactory {
    override fun rent(model: String) {
        println("BWM1 $model")
    }
}

class Mercedes {
    fun rentMercedes(model: String) {
        println("Mercedes $model")
    }
}

class Mercedes1 : CarManufactory {
    override fun rent(model: String) {
        println("Mercedes1 $model")
    }
}

class CarRentalAgency {
    fun rentCar(brand: String, model: String) {
        when (brand) {
            "BWM" -> {
                BWM().rentBWM(model)
            }
            "Mercedes" -> {
                Mercedes().rentMercedes(model)
            }
        }
    }
}

class CarRentalAgency1 {
    fun rentCar(cm: CarManufactory, model: String) {
        cm.rent(model)
    }
}

fun main() {
    val agency = CarRentalAgency()
    agency.rentCar("BWM", "T3")
    agency.rentCar("Mercedes", "AL")

    val agency1 = CarRentalAgency1()
    agency1.rentCar(BWM1(), "T3")
    agency1.rentCar(Mercedes1(), "AL")
}