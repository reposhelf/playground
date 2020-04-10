package org.muroniuk.tutorial.jdbc.basic;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

import org.myroniuk.tutorial.jdbc.ConnectionUtils;

public class ScrollableResultSetExample {

	public static void main(String[] args)
			throws SQLException, ClassNotFoundException {
		Connection connection = ConnectionUtils.getMyConnection();
		
		Statement statement = connection.createStatement(
				ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
		
		String sql = "SELECT EMP_ID, EMP_NO, EMP_NAME FROM EMPLOYEE";
		
		ResultSet rs = statement.executeQuery(sql);
		
		boolean last = rs.last();
		
		if (last) {
			System.out.println("EmpId:" + rs.getString(1));
			System.out.println("EmpNo:" + rs.getString(2));
			System.out.println("EmpName:" + rs.getString(3));
		}
		
		System.out.println("------------------------------");
		
		boolean previous = rs.previous();
		System.out.println("Previous1:" + previous);
		
		previous = rs.previous();
		System.out.println("Previous2:" + previous);
		
		while (rs.next()) {
			String empNo = rs.getString(2);
			String empId = rs.getString(1);
			String empName = rs.getString("EMP_NAME");
			System.out.println("-------------------");
			System.out.println("EmpId:" + empId);
			System.out.println("EmpNo:" + empNo);
			System.out.println("EmpName:" + empName);
		}
		connection.close();
	}
}
