package org.muroniuk.tutorial.jdbc.basic;

import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.ResultSet;

import org.myroniuk.tutorial.jdbc.ConnectionUtils;

public class PrepareStatementExample {

	public static void main(String[] args)
			throws SQLException, ClassNotFoundException {
		Connection connection = ConnectionUtils.getMyConnection();
		
        String sql = "SELECT emp.EMP_ID, emp.EMP_NO, emp.EMP_NAME,"
        		+ " emp.DEPT_ID FROM EMPLOYEE emp "
                + " WHERE emp.EMP_NAME LIKE ? AND emp.DEPT_ID = ? ";
        
        PreparedStatement pstm = connection.prepareStatement(sql);
		
		pstm.setString(1, "%S");
		pstm.setInt(2, 20);
		ResultSet rs = pstm.executeQuery();
		
		while (rs.next()) {
			System.out.println(" ---- ");
			System.out.println("EmpId:" + rs.getString(1));
			System.out.println("EmpNo:" + rs.getString(2));
			System.out.println("EmpName:" + rs.getString(3));
		}
		
		System.out.println();
		System.out.println("Set other parameters...");
		
		pstm.setString(1, "KI%");
		pstm.setInt(2, 10);
		rs = pstm.executeQuery();
		
		while (rs.next()) {
			System.out.println(" ---- ");
			System.out.println("EmpId:" + rs.getString(1));
			System.out.println("EmpNo:" + rs.getString(2));
			System.out.println("EmpName:" + rs.getString(3));
		}
		connection.close();
	}
}
