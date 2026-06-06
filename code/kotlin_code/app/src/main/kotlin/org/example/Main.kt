package org.example


fun main()
{
    val first_code = false
    val second_code = false
    val third_code = true

    if(first_code)
    {
        println("Input a number:")
        val input: Boolean? = readln().toIntOrNull()?.rem(2)?.equals(0) //rem = %, equals = ==
        println("Input is $input")
    }

    if(second_code)
    {
        val some_list: IntArray = intArrayOf(48, 28, 3, 0, 1)

        val some_pointer = some_list

        val input: String = when(readln().toIntOrNull())
                        {
                            null -> "Is null"
                            1 -> "Is one"
                            else -> "I WANT TO BE FREE!"
                        }

        val other_input: Int? = readln().toIntOrNull()

        if(other_input != null && other_input in 0..4) //some_list.size - to get size of array
        {
            println(some_list.getOrNull(other_input))
        }
        else
        {
            println("Whoopsie!")
        }

        println(input);
    }

    if(third_code)
    {
        println("How many values in array do you want?:")
        var amount_values = readln().toIntOrNull() ?: 0

        if(amount_values >= 0)
        {
            val some_values = IntArray(amount_values)

            while(amount_values > 0)
            {
                println("Write new value:")
                some_values[amount_values - 1] = readln().toIntOrNull() ?: 0

                val current_value: Int = some_values[amount_values - 1]

                println("Value is: $current_value")

                --amount_values;
            }
        }
    }
}
