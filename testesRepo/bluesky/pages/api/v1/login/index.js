import { createRouter } from 'next-connect';
import { BskyAgent } from '@atproto/api';
import controller from 'infra/controller.js';

const router = createRouter();

router.post(postHandler);

export default router.handler(controller.errorHandlers);

async function postHandler(request, response) {
  try{
  const {username, password} = request.body;
  console.log(username, password);
  const agent = new BskyAgent({
    service: 'https://bsky.social',
  });

  const responseLogin = await agent.login({identifier: username, password: password});
  console.log(responseLogin);
  response.status(201).json({ message: responseLogin });
} catch (error) {
  console.error(error);
  return response.status(400).json({ message: error.message });
}
}