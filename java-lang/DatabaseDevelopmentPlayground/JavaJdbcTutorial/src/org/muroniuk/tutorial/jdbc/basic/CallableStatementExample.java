package org.muroniuk.tutorial.jdbc.basic;

import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.Date;
import java.sql.SQLException;
 
import org.myroniuk.tutorial.jdbc.ConnectionUtils;

public class CallableStatementExample {

	public static void main(String[] args)
			throws ClassNotFoundException, SQLException {
		// Get a connection
		Connection connection = ConnectionUtils.getMyConnection();
		
		String sql = "{call get_Employee_Info(?,?,?,?,?)}";
		
		// Create a CallableStatement object.
		CallableStatement cstm = connection.prepareCall(sql);
		
		// Set parameter value for first question mark
		// (p_Emp_ID)
		cstm.setInt(1, 10);
		
		// Registers the OUT parameter for 2nd question mark.
		// (v_Emp_No)
		cstm.registerOutParameter(2, java.sql.Types.VARCHAR);
		
		// Registers the OUT parameter for 3rd question mark.
		// (v_First_Name)
		cstm.registerOutParameter(3, java.sql.Types.VARCHAR);
		
		// Registers the OUT parameter for 4th question mark.
		// (v_Last_Name)
		cstm.registerOutParameter(4, java.sql.Types.VARCHAR);
		
		// Registers the OUT parameter for 5th question mark.
		// (v_Hire_Date)
		cstm.registerOutParameter(5, java.sql.Types.DATE);
		
		// Execute statement.
		cstm.executeUpdate();
		
		String empNo = cstm.getString(2);
		String firstName = cstm.getString(3);
		String lastName = cstm.getString(4);
		Date hireDate = cstm.getDate(5);
		
		System.out.println("Emp No: " + empNo);
		System.out.println("First Name: " + firstName);
		System.out.println("Last Name: " + lastName);
		System.out.println("Hire Date: " + hireDate);
		
		connection.close();
	}
}
