<?php

namespace models;

use lib\Singleton;
use PDO;

/**
 * Description of DataBase
 *
 *  @date 09 02 2023
 *  @author Giovanni Ragno
 *  @copyright https://creativecommons.org/licenses/by-sa/4.0/
 */
class DataBase extends Singleton {
    const DSN="sqlite:data/maker.sqlite";
    /** @var PDO connessione al db */
    public PDO $conn;
    
    protected function __construct() {
        $this->conn = new PDO(self::DSN);
    }

}
