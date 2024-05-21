<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "batt_life_db";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT * FROM status1 WHERE id = '1'";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Output data of each row
    while($row = $result->fetch_assoc()) {
        echo $row["on_off"];
    }
} else {
    echo "0 results";
}
$conn->close();
?>
