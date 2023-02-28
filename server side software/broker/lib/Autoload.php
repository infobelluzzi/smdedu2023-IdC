<?php

namespace lib;


/**
 * Description of Autoload
 *
 *  @date 09 02 2023
 *  @author Giovanni Ragno
 *  @copyright https://creativecommons.org/licenses/by-sa/4.0/
 */
class Autoload {
    
        /**
         * registra la funzione di autoload
         */
	public static function autoload()
	{
		spl_autoload_register('self::loader');
	}
	
        /**
         * include il file con la dichiarazione della classe
         * @param string $class
         */
	public static function loader(string $class)
	{
		require str_replace('\\', '/', $class).'.php'; 
	}

}