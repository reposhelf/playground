package org.muroniuk.tutorial.jdbc.basic;

import java.sql.Connection;
import java.sql.SQLException;

import org.myroniuk.tutorial.jdbc.ConnectionUtils;

public class TransactionExample {

	private static void doJob1(Connection conn) {
		// Todo something here
	}
	
	private static void doJob2(Connection conn) {
		// Todo something here
	}
	
	public static void main(String[] args)
			throws SQLException, ClassNotFoundException {
        // Get a connection
        Connection connection = ConnectionUtils.getMyConnection();
            
        // Set auto-commit to false
        connection.setAutoCommit(false);
 
        try {
        	// Do something related to the DB.
            doJob1(connection);
            doJob2(connection);
  
            // Explicitly commit statements to apply changes
            connection.commit();
        }
        // Handling exception
        catch (Exception e) {
            e.printStackTrace();
  
            // Rollback changes
            connection.rollback();
        }
        // Close connection.
        connection.close();
	}
}
