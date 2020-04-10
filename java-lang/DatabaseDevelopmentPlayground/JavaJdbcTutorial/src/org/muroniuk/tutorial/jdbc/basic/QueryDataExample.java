package org.muroniuk.tutorial.jdbc.basic;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

import org.myroniuk.tutorial.jdbc.ConnectionUtils;

public class QueryDataExample {
	
	public static void main(String[] args)
			throws SQLException, ClassNotFoundException {
		Connection connection = ConnectionUtils.getMyConnection();
		
		Statement statement = connection.createStatement();
		
		String sql = "SELECT EMP_ID, EMP_NO, EMP_NAME from EMPLOYEE";
		
		ResultSet rs = statement.executeQuery(sql);
		
		while (rs.next()) {
			String empId = rs.getString(1);
			String empNo = rs.getString(2);
			String empName = rs.getString("EMP_NAME");
			System.out.println("-------------------");
			System.out.println("EmpId:" + empId);
			System.out.println("EmpNo:" + empNo);
			System.out.println("EmpName:" + empName);
		}
		connection.close();
	}
}
