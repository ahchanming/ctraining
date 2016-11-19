
MySockAddr::MySockAddr(){
	bzero(m_sockaddr, sizeof(m_sockaddr));
	m_sockaddr.sin_family = MySOcketAddr_IPv4;
	m_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
}

struct sockaddr* MySockAddr::GetPtSockAddr(){
	return (struct sockaddr*)m_sockaddr;
}


