package org.myroniuk.jstltutorial.beans;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.util.Date;

public class Emp {
	
	private int empNo;
	private String empName;
	private String job;
	
	private Date hireDate;
	private float salary;
	
	private static final DateFormat dateFormat =
			new SimpleDateFormat("MM/dd/yyyy");
	
	public Emp() {
	}
	
	// @hireDateStr  - must have the format 'MM/dd/yyyy'
	public Emp(int empNo, String empName, String job, String hireDateStr,
			float salary) {
		this.empNo = empNo;
		this.empName = empName;
		this.job = job;
		this.salary = salary;
		try {
			hireDate = dateFormat.parse(hireDateStr);
		} catch (ParseException e) {
			throw new RuntimeException(e);
		}
	}
	
	public int getEmpNo() {
		return this.empNo;
	}
	
	public void setEmpNo(int empNo) {
		this.empNo = empNo;
	}
	
	public String getEmpName() {
		return this.empName;
	}
	
	public void setEmpName(String empName) {
		this.empName = empName;
	}
	
	public String getJob() {
		return this.job;
	}
	
	public void setJob(String job) {
		this.job = job;
	}
	
	public Date getHireDate() {
		return this.hireDate;
	}
	
	public void setHireDate(Date hireDate) {
		this.hireDate = hireDate;
	}
	
	public float getSalary() {
		return this.salary;
	}
	
	public void setSalary(float salary) {
		this.salary = salary;
	}
}
